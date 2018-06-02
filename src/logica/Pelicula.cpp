#include "../../include/logica/Pelicula.h"
#include "../../include/logica/Comentario.h"
#include "../../include/logica/Puntaje.h"
Pelicula::~Pelicula()
{
    //dtor
}
        void Pelicula::setPoster(string poster){
            this->poster = poster;
        };

        void Pelicula::setSinopsis(string sinopsis){
            this->sinopsis = sinopsis;
        };
        void Pelicula::agregarComentario(string nickname, string comentario) {
            Comentario comentario = new Comentario(nickname, comentario);
            comentarios[comentario->getID()] = comentario;
        }
        void Pelicula::agregarComentario(string nickname, string comentario, int esRespuestaDeID) {
            Comentario comentario = new Comentario(nickname, comentario, esRespuestaDeID);
            comentarios[comentario->getID()] = comentario;
        }
        
        void Pelicula::modificarComentario(int id, string comentario) {
           Comentario comen = this->comentarios.find(id);
           comen->setComentairo(comentario);
        }
        
        void Pelicula::agregarPuntaje(string nickName, float puntaje){
            Puntaje puntaje = new Puntaje(nickName, puntaje);
            puntajes[puntaje->getID()] = puntaje;
        }
        
        void Pelicula::modificarPuntaje(string nickName, float puntaje) {
            Puntaje punt = this->puntajes.find(puntaje);
            punt->setPuntaje(puntaje);
        }
        
        float Pelicula::verPuntaje(string nickName) {
            Puntaje p = this->puntajes.find(nickName);
            return p->getPuntaje(); //PUEDE SER PUNTO O GUION?
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
                suma += puntajes[it->second];
                it++;
            }
            return suma/puntajes.size(); // CREO QUE ESTA TODO MAL....(O SEA SEGURAMENTE ESTE MAL, PORQUE LO HIZO EL CAMARADA)
        };

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

        Pelicula::~Pelicula();
