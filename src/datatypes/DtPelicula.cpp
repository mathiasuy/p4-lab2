#include "../../include/datatypes/DtPelicula.h"

DtPelicula::DtPelicula(string titulo, string poster, float puntajePromedio)
{
    this->poster = poster;
    this->puntajePromedio = puntajePromedio;
    this->titulo = poster;
}

DtPelicula::~DtPelicula()
{
    //dtor
}

string DtPelicula::getID(){
    return this->titulo;
};
string DtPelicula::getTitulo(){
    return this->titulo;
};
string DtPelicula::getPoster(){
    return this->poster;
};
float DtPelicula::getPuntajePromedio(){
    return this->puntajePromedio;
};
