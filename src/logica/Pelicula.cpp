#include "../../include/logica/Pelicula.h"
#include "iostream"

        Pelicula::~Pelicula()
        {

            std::map<string,Puntaje*>::iterator it = puntajes.begin();

            while ( it != puntajes.end()){
                Puntaje* p = it->second;
                delete p;
                it++;
            }

            std::map<int,Comentario*>::iterator it2 = comentarios.begin();
            while (it2 != comentarios.end()){
                Comentario* c = it2->second;
                delete c;
                it2++;
            }

        }

        void Pelicula::setPoster(string poster){
            this->poster = poster;
        };

        void Pelicula::setSinopsis(string sinopsis){
            this->sinopsis = sinopsis;
        };
        void Pelicula::agregarComentario(string nickname, string comentario) {
            Comentario* comentari = new Comentario(nickname, comentario);
            comentarios[comentari->getID()] = comentari;
        }
        void Pelicula::agregarComentario(string nickname, string comentario, int esRespuestaDeID) {
            Comentario* comentari = new Comentario(nickname, comentario, esRespuestaDeID);
            comentarios[comentari->getID()] = comentari;
        }

        void Pelicula::modificarComentario(int id, string comentario) {
           Comentario* comen = this->comentarios.find(id)->second;
           if (comen != NULL){
               comen->setComentairo(comentario);
           }
        }

        map<int,Funcion*> Pelicula::listarFunciones(){
            //cout << funciones.size() << "CANTIDAD EN EL CPP";
            return this->funciones;
        }

        bool Pelicula::agregarFuncion(Funcion* f){
            return this->funciones[f->getID()] = f;
        }

        bool Pelicula::quitarFuncion(int id){
            return this->funciones.erase(id);
        }

        void Pelicula::setPuntaje(string nickName, float puntaje) {
            if (this->puntajes.find(nickName) != puntajes.end()){
                Puntaje* puntaj = this->puntajes.find(nickName)->second;
                puntaj->setPuntaje(puntaje);
            }else{
                Puntaje* puntaj = new Puntaje(nickName, puntaje);
                this->puntajes[puntaj->getID()] = puntaj;
            }
        }

        Util::ListaDt<int,DtComentario> Pelicula::listarDtComentarios(){
            map<int,Comentario*>::iterator it = this->comentarios.begin();
            Util::ListaDt<int, DtComentario> dt;
            while (it != this->comentarios.end()){
                dt.add(it->second->getDt());
                it++;
            }
            return dt;
        }

        /**
         * Retorna -1 si nunca puntuo
         * */
        float Pelicula::getPuntaje(string nickName) {
            Puntaje* p = this->puntajes.find(nickName)->second;
            return ((p != NULL)?(p->getPuntaje()):-1); //PUEDE SER PUNTO O GUION?
        }

        string Pelicula::getPoster(){
            return this->poster;
        };

        string Pelicula::getSinopsis(){
            return this->sinopsis;
        };

        DtPelicula Pelicula::getDt(){
            return  DtPelicula(this->titulo, this->poster, this->sinopsis, this->getPuntajePromedio());
        };

        Util::ListaDt<string,DtPuntaje> Pelicula::listarDtPuntajes(){
            Util::ListaDt<string,DtPuntaje> dt;
            map<string, Puntaje*>::iterator it = puntajes.begin();
            while (it != puntajes.end()){
                dt.add(it->second->getDt());
                it++;
            }
            return dt;
        };

        float Pelicula::getPuntajePromedio(){
            map<string,Puntaje*>::iterator it = puntajes.begin();
            float suma = 0;
            while (it != puntajes.end()){
                suma += puntajes[it->second->getID()]->getPuntaje();
                it++;
            }
            return suma/puntajes.size(); // CREO QUE ESTA TODO MAL....(O SEA SEGURAMENTE ESTE MAL, PORQUE LO HIZO EL CAMARADA)
        };

        string Pelicula::getTitulo(){
            return this->titulo;
        };

        string Pelicula::getID(){
            return this->getTitulo();
        };

        string Pelicula::toString(){
            return "Esta es la pel�cula: " + this->getTitulo();
        };

        bool Pelicula::isEqual(Pelicula *pelicula){
            return this->getID() == pelicula->getID();
        };


        /* CONSTRUS Y DESTRUS */

        Pelicula::Pelicula(string titulo, string poster, string sinopsis){
            this->titulo = titulo;
            this->setPoster(poster);
            this->setSinopsis(sinopsis);
        };



