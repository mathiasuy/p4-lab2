#include "../../include/logica/Sistema.h"

        Sistema* Sistema::instancia = NULL;
        ManejadorCines* Sistema::cines = ManejadorCines::getInstancia();
        ManejadorFunciones* Sistema::funciones = ManejadorFunciones::getInstancia();
        ManejadorUsuarios* Sistema::usuarios = ManejadorUsuarios::getInstancia();
        ManejadorPeliculas* Sistema::peliculas = ManejadorPeliculas::getInstancia();

        Sistema::Sistema(){};
        Sistema* Sistema::getInstance(){
            if (instancia == NULL){
                instancia = new Sistema;
            }
            return Sistema::instancia;
        }
        /*   CINES   */
        bool Sistema::altaCine(string direccion, vector<int> capacidadSalas){
            Cine* cineNuevo = new Cine(direccion, capacidadSalas);
            cines->add(cineNuevo);
            return true;
        };
        /*  PELICULA */
        bool Sistema::altaFuncion(float precioEntrada, DtFecha fecha, int idSala, int idCine, string tituloPelicula){
            Sala* sala = this->cines->find(idCine)->getSala(idSala);
            Pelicula* pelicula = this->peliculas->find(tituloPelicula);
            Funcion* fnueva = new Funcion(precioEntrada, fecha, sala, pelicula);
            this->funciones->add(fnueva);
            return true;
        };
        float Sistema::getPuntajePelicula(string nickName, string tituloPelicula){
            if (peliculas->isMember(tituloPelicula)){
                return peliculas->find(tituloPelicula)->getPuntaje(nickName);
            }else
                return -1;
        };
        bool Sistema::puntuarPelicula(string nickName, string tituloPelicula, float puntaje){
            if (peliculas->isMember(tituloPelicula)){
                peliculas->find(tituloPelicula)->setPuntaje(nickName, puntaje);
                return true;
            }else
                return false;
        }
        bool Sistema::comentarPelicula(string nickName, string tituloPelicula, string comentario, int esRespuestaDeID){
            if (peliculas->isMember(tituloPelicula)){
                this->peliculas->find(tituloPelicula)->agregarComentario(nickName,comentario,esRespuestaDeID);
                return true;
            }else
                return false;
        }
        bool Sistema::comentarPelicula(string nickName, string tituloPelicula, string comentario){
            if (peliculas->isMember(tituloPelicula)){
                this->peliculas->find(tituloPelicula)->agregarComentario(nickName,comentario);
                return true;
            }else
                return false;
        }
        bool Sistema::eliminarPelicula(string titulo){
            if(peliculas->isMember(titulo)){
                //aca tengo un puntero al objeto
                Pelicula* pelicula = peliculas->find(titulo);
                map<int,Funcion*> funciones = pelicula->listarFunciones();
                for (std::map<int, Funcion*>::iterator it = funciones.begin(); it != funciones.end(); ++it)
                {
                  Funcion* funcion = it->second;
                  usuarios->beginIterator();
                  while(usuarios->getElement()){
                      if(usuarios->getElement()->tieneReservaFuncion(funcion->getID())){
                          usuarios->getElement()->eliminarReservaConFuncion(funcion->getID());
                      };
                      usuarios->next();
                  }
                  Sala *sala = funcion->getSala();
                  if (sala->tieneFuncion(funcion->getID())){
                      sala->quitarFuncion(funcion);
                  }
                  pelicula->quitarFuncion(funcion->getID());
                  delete funcion;
                }
                delete pelicula;
                return true;
            }
            else return false;
        };
        /* USUARIO */
        bool Sistema::login(string nickName, string password){
            if(usuarios->isMember(nickName)){
             //si esta, lo busco
             Usuario* usuario = usuarios->find(nickName);
             return ((usuario != NULL)?(usuario->getPassword() == password):false);
            }
            else return false;
        };
        bool Sistema::crearReserva(string nickName,int cantAsientos,int idFuncion,string financiera, float descuento, float montoTotal){
            Funcion* funcion = this->funciones->find(idFuncion);
            if (funcion->getAsientosLibres()>cantAsientos){
                this->usuarios->find(nickName)->agregarReservaCredito(cantAsientos,funcion,financiera,descuento,montoTotal);
                return true;
            }else{
                return false;
            }
        };
        bool Sistema::crearReserva(string nickName, int cantAsientos,int idFuncion,string banco, float montoTotal){
            Funcion* funcion = this->funciones->find(idFuncion);
            if (funcion->getAsientosLibres()>cantAsientos){
                this->usuarios->find(nickName)->agregarReservaDebito(cantAsientos, funcion, banco, montoTotal);
                return true;
            }else{
                return false;
            }
        };


        /***********************************************************************************/
        /***********************************************************************************/
        /*****************************     N U E V O S     *********************************/
        /***********************************************************************************/
        /***********************************************************************************/

        /* LISTAR TODAS LAS PELICULAS */
        ListaDt<string,DtPelicula> listarPeliculas(){
            this->peliculas.beginIterator();
            ListaDt<string,DtPelicula> dt;
            while (this->peliculas->end()){
                dt.add(this->peliculas->getElement());
                this->peliculas->next();
            }
            return dt;
        };

        /* LISTAR TODOS LOS CINES */
        ListaDt<int,DtCine> listarCines(){
            this->peliculas.beginIterator();
            ListaDt<string,DtCine> dt;
            while (this->cines->end()){
                dt.add(this->cines->getElement());
                this->cines->next();
            }
            return dt;
        };

        /* LISTAR SALAS X CINE */
        ListaDt<int,DtSala> listarSalas(int idCine){
            Cine* cine = this->cines->find(idCine);
            return cine->listarDtSalas();
        };

        /* LISTAR CINES X PELICULA */
        ListaDt<int,DtCine> listarCines(string titulo){
            Pelicula* pelicula = this->peliculas.find(titulo);
            map<int,Funcion*> funciones = pelicula->listarFunciones();
            map<int,Funcion*>::iterator it = funciones.begin();
            ListaDt<int,DtCine> dt;
            while (it != funciones.end()){
                Funcion* f = it->second;
                if (f->getPelicula()->isEqual(pelicula)){
                    dt.add(f->getSala()->getCine()->getDtCine());
                }
                it++;
            }
            return dt;
        };

        /* LISTAR COMENTARIOS X PELICULA */
        ListaDt<int,DtComentario> listarComentarios(string titulo){
            Pelicula* pelicula = this->peliculas->find(titulo);
            return pelicula->listarDtComentarios();
        };

        /* LISTAR FUNCIONES X PELICULA Y CINE  POSTARIOR A FECHA Y HORA ACTUAL*/
        ListaDt<int,DtFuncion> listarFunciones(int idCine, string titulo, DtFecha fecha){
            Cine* cine = this->cines->find(idCine);
            map<int,Funcion*> fs = this->peliculas->find(titulo)->listarFunciones();
            map<int,Funcion*>::iterator it = it.begin();
            ListDt<string,Funcion> dt;
            while (it != fs.end()){
                if (!fs.second->getSala()->getCine()->getID() == titulo){
                    dt.add(fs.second);
                }
                it++;
            }
            return dt;
        };

        /* LISTAR PUNTAJES X PELICULA */
        ListaDt<string,DtPuntaje> listarPuntajes(string titulo){
            Pelicula* pelicula = this->peliculas->find(titulo);
            return pelicula->listarDtPuntajes();
        };

        /* LISTAR RESERVAS X USUARIO */
        ListaDt<int,DtReserva> listarReservas(string nickName){
            Reserva* reserva = this->usuarios->find(nickName)->listarReservas();
            return pelicula->listarDtPuntajes();
        };


        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/


        DtTest Sistema::test(){

            int m1[] = {3, 2, 1, 0, 4, 6, 7, 8};
            vector<int> v1(m1, m1 + sizeof(m1) / sizeof (*m1) );
            this->altaCine("18 de Julio 2042",v1);

            int m2[] = {3, 2, 1, 0, 4, 6, 7, 8};
            vector<int> v2(m2, m2 + sizeof(m2) / sizeof (*m2) );
            this->altaCine("Av. Garzon 555",v2);

            int m3[] = {3, 2, 1, 0, 4, 6, 7, 8};
            vector<int> v3(m3, m3 + sizeof(m3) / sizeof (*m3) );
            this->altaCine("Julio Herrera y Reissing 565",v3);

            Pelicula* p = new Pelicula("La Matanza","https://www.fing.edu.uy/inco/cursos/p4/parciales/bienvenida.jpg","Un grupo de estudiantes luchan por sobrevivir al InCo");

            this->peliculas->add(p);
/*
            p = new Pelicula("Hola m","img/foto1.jpg","bla, bla, bla, bla, esto es una sinopsis");
            this->peliculas->add(p);
            p = new Pelicula("Teens Russians","img/foto2.jpg","Un grupo de chicas estudiantes luchan por conseguir la paz en un mundo tan descontrolado. Actuan: Milka Ferreira");
            this->peliculas->add(p);


            DtFecha f1(5,10,2016,14,0);
            DtFecha f2(5,10,2017,15,0);
            DtFecha f3(5,10,2018,14,0);
            DtFecha f4(5,10,2019,14,0);
            this->altaFuncion(5,f1,1,1,"La Matanza");
            this->altaFuncion(5,f4,2,2,"Hola m");
            this->altaFuncion(5,f3,2,2,"Hola m");
            this->altaFuncion(5,f4,2,2,"Teens Russians");

            Usuario* u = new Usuario("Admin","imagenAdmin","A");
            this->usuarios->add(u);
            u = new Usuario("A","imagenA","A");
            this->usuarios->add(u);
            u = new Usuario("B","imagenB","A");
            this->usuarios->add(u);
            u = new Usuario("C","imagenC","C");
            this->usuarios->add(u);
            u = new Usuario("D","imagenD","D");
            this->usuarios->add(u);
            u = new Usuario("E","imagenE","E");
            this->usuarios->add(u);

            this->crearReserva("A",12,1,"BROU", 5);
            this->crearReserva("B",5,2,"Abitab",5,10);

            this->comentarPelicula("A","La Matanza","Sin palabras.");
            this->comentarPelicula("B","La Matanza","Conmovedora");
            this->puntuarPelicula("A","La Matanza",5);
            this->puntuarPelicula("B","Hola m",4);
            this->comentarPelicula("A","Teens Russians","Yo no la vi, no puedo opinar.");
            int a = this->getPuntajePelicula("A","La Matanza");
            int b = this->getPuntajePelicula("B","Hola m");
            DtTest d(a,b);

            this->comentarPelicula("C","La matanza","Si.",1);

            this->login("A","A");
            this->login("A","B");
            this->crearReserva("A",4,2,"BROU",5);
            this->eliminarPelicula("Teens Russians");
            return d;
*/
			DtTest v;
			return v;

        };


