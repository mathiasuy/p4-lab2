#include "../../include/datatypes/DtFuncion.h"

DtFuncion::DtFuncion(){
    this->id = 0;
    this->asientosReservados = 0;
    this->precioEntrada = 0;//ctor
}

DtFuncion::DtFuncion(int id, int asientosReservados, float precioEntrada, DtSala sala, DtPelicula pelicula){
    this->id = id;
    this->asientosReservados = asientosReservados;
    this->precioEntrada = precioEntrada;
    this->sala = sala;
    this->pelicula = pelicula;
};

int DtFuncion::getID(){
    return this->id;
};

int DtFuncion::getAsientosReservados(){
    return this->asientosReservados;
};
float DtFuncion::getPrecio(){
    return this->precioEntrada;
};

bool DtFuncion::isEqual(DtFuncion* Funcion){
    return this->getID() == Funcion->getID();
};

 string DtFuncion::toString(){
     return "Datos de la funcion " + this->getID() + this->sala->toString();
 };


DtFuncion::~DtFuncion()
{
    //dtor
}
