#include "../../include/logica/Pelicula.h"
#include "../../include/logica/Comentario.h"
#include "../../include/logica/Puntaje.h"
        
        Pelicula::~Pelicula()
        {
            map<string,Puntaje*>::iterator it;
            for (it = puntajes.begin(); it != puntajes.end(); ++it)
                delete it->second;
            map<string,Comentario*>::iterator it;
            for (it = comentarios.begin(); it != comentarios.end(); ++it)
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
/*
        void Pelicula::modificarComentario(int id, string comentario) {

           Comentario* comen = this->comentarios.find(id);
           comen->setComentairo(comentario);

        }

        void Pelicula::agregarPuntaje(string nickName, float puntaje){
            Puntaje* puntaj = new Puntaje(nickName, puntaje);
            puntajes[puntaj->getID()] = puntaj;
        }

        void Pelicula::modificarPuntaje(string nickName, float puntaje) {
            Puntaje punt = this->puntajes.find(puntaje);
            punt->setPuntaje(puntaje);
        }

        float Pelicula::verPuntaje(string nickName) {
            Puntaje p = this->puntajes.find(nickName);
            return p->getPuntaje(); //PUEDE SER PUNTO O GUION?
        }
*/
        string Pelicula::getPoster(){
            return this->poster;
        };

        string Pelicula::getSinopsis(){
            return this->sinopsis;
        };
/*
        float Pelicula::getPuntajePromedio(){
            map<int,Puntaje*>::iterator it = puntajes.begin();
            float suma, aux = 0;
            while (it != puntajes.end()){
                suma += puntajes[it->second()];
                it++;
            }
            return suma/puntajes.size(); // CREO QUE ESTA TODO MAL....(O SEA SEGURAMENTE ESTE MAL, PORQUE LO HIZO EL CAMARADA)
        };
*/
        string Pelicula::getTitulo(){
            return this->getTitulo();
        };

        string Pelicula::getId(){
            return this->getTitulo();
        };

        string Pelicula::toString(){
            return "Esta es la pel�cula: " + this->getTitulo();
        };

        bool Pelicula::isEqual(Pelicula *pelicula){
            return this->getId() == pelicula->getId();
        };


        /* CONSTRUS Y DESTRUS */
        Pelicula::Pelicula(string titulo){
            this->titulo = titulo;
        };

        Pelicula::Pelicula(string titulo, string poster, string sinopsis, float puntajePromedio){
            this->titulo = titulo;
            this->setPoster("N/D");
            this->setSinopsis("N/D");
        };
