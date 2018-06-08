#include "../../include/datatypes/DtPelicula.h"

DtPelicula::DtPelicula(){
    titulo = "";
    poster = "";
    puntajePromedio = 0;
};

DtPelicula::DtPelicula(string titulo, string poster, string sinopsis float puntajePromedio){
    this->poster = poster;
    this->sinopsis = sinopsis;
    this->puntajePromedio = puntajePromedio;
    this->titulo = titulo;
};

string DtPelicula::getID(){
    return this->titulo;
};
string DtPelicula::getTitulo(){
    return this->titulo;
};
string DtPelicula::getPoster(){
    return this->poster;
};
string DtPelicula::getSinopsis(){
    return this->sinopsis;
};
float DtPelicula::getPuntajePromedio(){
    return this->puntajePromedio;
};

string DtPelicula::toString(){
    return "Pelicula:" + this->getID() + this->getPoster() + this->getSinopsis() ;
};

DtPelicula::~DtPelicula()
{
    //dtor
}