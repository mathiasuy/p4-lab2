#include "../../include/logica/Pelicula.h"

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

        string Pelicula::getPoster(){
            return this->poster;
        };

        string Pelicula::getSinopsis(){
            return this->sinopsis;
        };

        float Pelicula::getPuntajePromedio(){
            return 0; // IMPLEMENTAR!!
        };

        string Pelicula::getTitulo(){
            return this->getTitulo();
        };

        string Pelicula::getId(){
            return this->getTitulo();
        };

        string Pelicula::toString(){
            return "Esta es la película: " + this->getTitulo();
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
