#include "../../include/logica/Pelicula.h"

        Pelicula::~Pelicula()
        {
            std::map<string,Puntaje*>::iterator it;
            for (it = puntajes.begin(); it != puntajes.end(); ++it)
                delete it->second;
            std::map<int,Comentario*>::iterator it2;
            for (it2 = comentarios.begin(); it2 != comentarios.end(); ++it2)
                delete it->second;
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
            return this->funciones;
        }

        bool Pelicula::quitarFuncion(int id){
            this->funciones.erase(id);
        }

        void Pelicula::agregarPuntaje(string nickName, float puntaje){
            Puntaje* puntaj = new Puntaje(nickName, puntaje);
            this->puntajes[puntaj->getID()] = puntaj;
        }

        void Pelicula::setPuntaje(string nickName, float puntaje) {
            Puntaje* punt = this->puntajes.find(nickName)->second;
            if (punt != NULL){
                punt->setPuntaje(puntaje);
            }else{
                this->agregarPuntaje(nickName,puntaje);
            }
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
            return this->getTitulo();
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
            this->setPoster("N/D");
            this->setSinopsis("N/D");
        };
