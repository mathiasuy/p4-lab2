#include "../../include/datatypes/DtPelicula.h"

DtPelicula::DtPelicula(){
    titulo = "";
    poster = "";
    puntajePromedio = 0;
};

DtPelicula::DtPelicula(string titulo, string poster, float puntajePromedio)
{
    this->poster = poster;
    this->puntajePromedio = puntajePromedio;
    this->titulo = poster;
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

DtPelicula::~DtPelicula()
{
    //dtor
}