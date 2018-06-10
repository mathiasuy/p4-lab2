#include "../../include/datatypes/DtPelicula.h"

DtPelicula::DtPelicula(){
    titulo = "";
    poster = "";
    puntajePromedio = 0;
};

DtPelicula::DtPelicula(string titulo, string poster, string sinopsis, float puntajePromedio){
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
    return this->getID() + "\n";
};

DtPelicula::~DtPelicula()
{
    //dtor
}

    ostream& operator<<(ostream& os, DtPelicula& dt)
    {
        string b = "";
        b += "**********\n";
        b += dt.getPoster() + "\n";
        b += string("*********") + "\n";
        b += dt.getSinopsis() + "\n";
        b += "*********\n";
        os << b;
        return os;
    }
