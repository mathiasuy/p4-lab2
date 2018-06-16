#include "../../include/logica/Sistema.h"

        Sistema* Sistema::instancia = NULL;
        ManejadorCines* Sistema::cines = ManejadorCines::getInstancia();
        ManejadorFunciones* Sistema::funciones = ManejadorFunciones::getInstancia();
        ManejadorUsuarios* Sistema::usuarios = ManejadorUsuarios::getInstancia();
        ManejadorPeliculas* Sistema::peliculas = ManejadorPeliculas::getInstancia();

        float Sistema::getDescuento(string financiera){
            map<string,float> financieras;
            financieras["F1"] = 1;
            financieras["OCA"] = 15;
            financieras["SD"] = 0;
            financieras["F4"] = 4;
            return financieras[financiera];
        }



        Reloj* reloj = Reloj::getInstancia();

        Sistema::Sistema(){};
        Sistema* Sistema::getInstance(){
            if (instancia == NULL){
                instancia = new Sistema;
            }
            return Sistema::instancia;
        }

        /*  RELOJ  */
        DtFecha Sistema::getFechaActual(){
            return reloj->getFechaActual();
        }

        void Sistema::setFechaActual(int dia, int mes, int anio, int hora, int minuto){
            reloj->setAnio(anio);
            reloj->setMes(mes);
            reloj->setDia(dia);
            reloj->setHora(hora);
            reloj->setMinuto(minuto);
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
            //cout << "\nSALA: " << sala->toString();
            Pelicula* pelicula = this->peliculas->find(tituloPelicula);
            //cout << "\nPELICULA: " << pelicula->toString();
            Funcion* fnueva = new Funcion(precioEntrada, fecha, sala, pelicula);
            //cout << "\nFUNCION: " << fnueva->toString();
            this->funciones->add(fnueva);
            pelicula->agregarFuncion(fnueva);
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
                Pelicula* p = peliculas->find(tituloPelicula);
                cout << (p->getDt().toString());
                p->setPuntaje(nickName, puntaje);
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

                //cout << funciones.size() << "CANMTIDAD" << endl;

                std::map<int, Funcion*>::iterator it = funciones.begin();

                while (it != funciones.end())
                {
                  Funcion* funcion = it->second;
                  usuarios->beginIterator();

                  while(usuarios->getElement() != NULL){
                      Usuario* u = usuarios->getElement();
                        int idF = funcion->getID();
                        bool k = u->tieneReservaFuncion(idF);
                      if(k){
                          usuarios->getElement()->eliminarReservaConFuncion(funcion->getID());
                      };
                      usuarios->next();
                  }

                  Sala *sala = funcion->getSala();
                  if (sala->tieneFuncion(funcion->getID())){
                      sala->quitarFuncion(funcion);
                  }
                  pelicula->quitarFuncion(funcion->getID());
                  this->funciones->remove(funcion->getID());
                  delete funcion;
                  it++;
                }
                delete pelicula;

                return this->peliculas->remove(titulo);
            }

            else return false;
        };
        /* USUARIO */
        bool Sistema::login(string nickName, string password){
            if(usuarios->isMember(nickName)){
             //si esta, lo busco
             Usuario* usuario = usuarios->find(nickName);
             return usuario->getPassword() == password;
            }
            else
                return false;
        };

        /*  CREDITO  */
        bool Sistema::crearReserva(string nickName,int cantAsientos,int idFuncion,string financiera, float descuento, float montoTotal){
            Funcion* funcion = this->funciones->find(idFuncion);
            if (funcion->getAsientosLibres()>cantAsientos){
                this->usuarios->find(nickName)->agregarReservaCredito(cantAsientos,funcion,financiera,descuento,montoTotal);
                return true;
            }else{
                return false;
            }
        };

        /*  DEBITO  */
        bool Sistema::crearReserva(string nickName, int cantAsientos,int idFuncion,string banco, float montoTotal){
            Funcion* funcion = this->funciones->find(idFuncion);
            if (funcion->getAsientosLibres() > cantAsientos){
                cout << "Se va a crear una reserva " << endl;
                Usuario* u = this->usuarios->find(nickName);
                u->agregarReservaDebito(cantAsientos, funcion, banco, montoTotal);
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

        using namespace Util;

        /* LISTAR TODAS LAS PELICULAS */
        ListaDt<string,DtPelicula> Sistema::listarPeliculas(){
            this->peliculas->beginIterator();
            ListaDt<string,DtPelicula> dt;
            while (this->peliculas->getElement() != NULL){
                dt.add(this->peliculas->getElement()->getDt());
                this->peliculas->next();
            }
            return dt;
        };

        /* LISTAR TODOS LOS CINES */
        ListaDt<int,DtCine> Sistema::listarCines(){
            this->cines->beginIterator();
            ListaDt<int,DtCine> dt;
            while (this->cines->getElement() != NULL){
                dt.add(this->cines->getElement()->getDt());
                this->cines->next();
            }
            return dt;
        };

        /* LISTAR TODAS LAS FUNCIONES */
        ListaDt<int,DtFuncion> Sistema::listarFunciones(){
            cout << "llegosdsd";
            this->funciones->beginIterator();
            ListaDt<int,DtFuncion> dt;
            while (this->funciones->getElement() != NULL){
             cout << this->funciones->getElement()->getDt().toString();
               dt.add(this->funciones->getElement()->getDt());
               this->funciones->next();
            }
            return dt;
        };

        /* LISTAR SALAS X CINE */
        ListaDt<int,DtSala> Sistema::listarSalas(int idCine){
            Cine* cine = this->cines->find(idCine);
            return cine->listarDtSalas();
        };

        /* LISTAR CINES X PELICULA */
        ListaDt<int,DtCine> Sistema::listarCines(string titulo){
            Pelicula* pelicula = this->peliculas->find(titulo);
            map<int,Funcion*> funciones = pelicula->listarFunciones();
            map<int,Funcion*>::iterator it = funciones.begin();
            ListaDt<int,DtCine> dt;
            while (it != funciones.end()){
                Funcion* f = it->second;
                dt.add(f->getSala()->getCine()->getDt());
                it++;
            }
            return dt;
        };

        /* LISTAR COMENTARIOS X PELICULA */
        ListaDt<int,DtComentario> Sistema::listarComentarios(string titulo){
            Pelicula* pelicula = this->peliculas->find(titulo);
            return pelicula->listarDtComentarios();
        };

        /* LISTAR FUNCIONES X PELICULA Y CINE */
        ListaDt<int,DtFuncion> Sistema::listarFunciones(int idCine, string titulo, DtFecha fecha){
            Pelicula* p = this->peliculas->find(titulo);
            map<int,Funcion*> fs = p->listarFunciones();
            map<int,Funcion*>::iterator it = fs.begin();
            ListaDt<int,DtFuncion> dt;
            while (it != fs.end()){
                if (it->second->getSala()->esDeCine(idCine)){
                    dt.add(it->second->getDt());
                }
                it++;
            }
            return dt;
        };

        /* LISTAR PUNTAJES X PELICULA */
        ListaDt<string,DtPuntaje> Sistema::listarPuntajes(string titulo){
            Pelicula* pelicula = this->peliculas->find(titulo);
            return pelicula->listarDtPuntajes();
        };

        /* LISTAR RESERVAS X USUARIO */
        ListaDt<int,DtReserva> Sistema::listarReservas(string nickName){
            Usuario* u = this->usuarios->find(nickName);
            cout << "Usuario: " << u->getNickName() <<endl;
            cout << "Usuario: " << u->getNickName() <<endl;
            ListaDt<int,DtReserva> r = u->listarDtReservas();
            return r;
        };


        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/

        DtTest Sistema::testInCo(){
                ///********************CINES******************

                            cout << "Cantidad de Cines: "<< this->cines->size() << endl;
                            int m2[] = {20, 60, 30};
                            vector<int> v2(m2, m2 + sizeof(m2) / sizeof (*m2) );
                            cout << ((this->altaCine("21 de Septiembre 6658",v2))?"":"MAL");
                            cout << "Cantidad de Cines: "<< this->cines->size() << endl;
                            int m3[] = {60, 200};
                            vector<int> v3(m3, m3 + sizeof(m3) / sizeof (*m3) );
                            cout << ((this->altaCine("Miguel Barreiro 4588",v3))?"":"MAL");

                            cout << "Cantidad de Cines: "<< this->cines->size() << endl;

                /// ********************PELICULAS******************

                            Pelicula* p = new Pelicula("The Vindicators 3","/home/accion/posters/vindicators.png","Tercera entrega de la saga de superheroes.");
                            this->peliculas->add(p);
                            p = new Pelicula("Sangre de campeones","/home/accion/posters/scampeones.png","Documental");
                            this->peliculas->add(p);
                            p = new Pelicula("El insulto"," /home/accion/posters/elinsulto.png","Drama libanés");
                            this->peliculas->add(p);
                            p = new Pelicula("La noche que no se repite","/home/accion/posters/nr.png","Tremenda pelicula uruguaya");
                            this->peliculas->add(p);

                /// *******************FUNCIONES***************** */
                            DtFecha f1(15,6,2018,14,0);
                            DtFecha f2(15,6,2018,16,30);
                            DtFecha f3(15,6,2018,14,0);
                            DtFecha f4(15,6,2018,22,0);
                            this->altaFuncion(300,f1,1,1,"The Vindicators 3");
                            this->altaFuncion(300,f2,1,1,"Sangre de campeones");
                            this->altaFuncion(250,f3,1,2,"The Vindicators 3");
                            this->altaFuncion(300,f4,3,1,"El insulto");

                            cout << "\nSE CARGARON " << this->funciones->size() << " funciones. \n";

                            cout << "\nFuncion 1: " << (*funciones)[1].toString() << " . \n";
                            cout << "\nFuncion 2: " << (*funciones)[2].toString() << " . \n";
                            cout << "\nFuncion 3: " << (*funciones)[3].toString() << " . \n";
                            cout << "\nFuncion 4: " << (*funciones)[4].toString() << " . \n";

                // *******************uSUARIOS*****************

                            Usuario* u = new Usuario("chachoElNumberOne","/users/registered/chachoElNumberOne.png","jorgeP4");
                            this->usuarios->add(u);
                            u = new Usuario("carmeBeiro2010","/users/registered/carmeBeiro2010.png","carmela5688");
                            this->usuarios->add(u);
                            u = new Usuario("ale_ulises","/admin/registered/ale_ulises.png","p4eslomejor21");
                            this->usuarios->add(u);

                            u = new Usuario("nico","/admin/registered/nico.png","1234");
                            this->usuarios->add(u);

                // *******************FINANCIERAS*****************


                // *******************COMENTARIOS*****************

                            this->comentarPelicula("chachoElNumberOne","The Vindicators 3","Es tremenda pelicula. La mejor parte es cuando aparecen Rick y Morty.");
                            this->comentarPelicula("carmeBeiro2010","The Vindicators 3","Esta muy buena pero la mejor parte es cuando explota el planeta con los malo",1);
                            this->comentarPelicula("chachoElNumberOne","The Vindicators 3","Callateee no cuentes el final!!",2);

                /// *******************PUNTAJES*****************

                            this->puntuarPelicula("chachoElNumberOne","The Vindicators 3",9);
                            this->puntuarPelicula("carmeBeiro2010","La noche que no se repite",6);

                /// *******************RESERVAS*****************

                            this->crearReserva("chachoElNumberOne",7,1,"BROU",300);
                            this->crearReserva("carmeBeiro2010",8,1,"OCA",15,300);
/*
*/
            DtTest d;
            return d;
        }

        DtTest Sistema::test(){


            //cout << "ANTES: " << Utils::aString(usuarios->size());
            Usuario* u = new Usuario("Admin","imagenAdmin","A");
            this->usuarios->add(u);
            u = new Usuario("ale_ulises","avatar","p");
            this->usuarios->add(u);
            //cout << "DESPUES: " << Utils::aString(usuarios->size());
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


            cout << "Cantidad de Cines: "<< this->cines->size() << endl;
            int m1[] = {30, 20, 10, 00, 40, 60, 70, 80};
            vector<int> v1(m1, m1 + sizeof(m1) / sizeof (*m1) );

            cout << ((this->altaCine("18 de Julio 2042",v1))?"":"MAL") << endl;

            cout << "Cantidad de Cines: "<< this->cines->size() << endl;
            int m2[] = {10, 20, 10, 05, 40, 60, 70, 80};
            vector<int> v2(m2, m2 + sizeof(m2) / sizeof (*m2) );
            cout << ((this->altaCine("Av. Garzon 555",v2))?"":"MAL");

            cout << "Cantidad de Cines: "<< this->cines->size() << endl;
            int m3[] = {30, 20, 10, 00, 40, 60, 70, 80};
            vector<int> v3(m3, m3 + sizeof(m3) / sizeof (*m3) );
            cout << ((this->altaCine("Julio Herrera y Reissing 565",v3))?"":"MAL");

            cout << "Cantidad de Cines: "<< this->cines->size() << endl;


            //cout << "\nchuppame " << (((this->cines->getElement(1)) == NULL)?"ES NULL":"NO ES NULL");
//            this->cines->beginIterator();
//            while(this->cines->getElement() != NULL){
//                cout << "\nchuppame " << this->cines->getElement()->toString();
//                this->cines->next();
//            }



            Pelicula* p = new Pelicula("La Matanza","https://www.fing.edu.uy/inco/cursos/p4/parciales/bienvenida.jpg","Un grupo de estudiantes luchan por sobrevivir al InCo");
            this->peliculas->add(p);
            p = new Pelicula("Hola m","img/foto1.jpg","bla, bla, bla, bla, esto es una sinopsis");
            this->peliculas->add(p);
            p = new Pelicula("Teens Russians","img/foto2.jpg","Un grupo de chicas estudiantes luchan por conseguir la paz en un mundo tan descontrolado. Actuan: Milka Ferreira");
            this->peliculas->add(p);


            DtFecha f1(5,10,2019,14,0);
            DtFecha f2(5,10,2019,15,0);
            DtFecha f3(5,10,2019,14,0);
            DtFecha f4(5,10,2019,14,0);
            this->altaFuncion(5,f1,1,1,"La Matanza");
            this->altaFuncion(5,f4,2,2,"Hola m");
            this->altaFuncion(5,f3,2,2,"Hola m");
            this->altaFuncion(5,f4,2,2,"Teens Russians");

            cout << "\nSE CARGARON " << this->funciones->size() << " funciones. \n";

            cout << "\nFuncion 1: " << (*funciones)[1].toString() << " . \n";
            cout << "\nFuncion 2: " << (*funciones)[2].toString() << " . \n";
            cout << "\nFuncion 3: " << (*funciones)[3].toString() << " . \n";
            cout << "\nFuncion 4: " << (*funciones)[4].toString() << " . \n";

            this->crearReserva("A",2,1,"BROU", 5);
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
            //this->login("A","B");
            this->crearReserva("A",4,2,"BROU",5);


            //this->eliminarPelicula("Teens Russians");
/*
            return d;
*/
			DtTest v;

			return v;

        };
