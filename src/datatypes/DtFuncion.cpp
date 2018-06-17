#include "../../include/datatypes/DtFuncion.h"
#include "../../include/Utils.h"

DtFuncion::DtFuncion(){
    this->id = 0;
    this->asientosReservados = 0;
    this->precioEntrada = 0;//ctor
}

DtFuncion::DtFuncion(int id, int asientosReservados, DtFecha f, float precioEntrada, DtSala sala, DtPelicula pelicula){
    this->id = id;
    this->asientosReservados = asientosReservados;
    this->precioEntrada = precioEntrada;
    this->sala = sala;
    this->pelicula = pelicula;
    this->fecha = f;
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

DtPelicula DtFuncion::getPelicula(){
    return this->pelicula;
};

DtFecha DtFuncion::getFecha(){
   return this->fecha;
};

DtSala DtFuncion::getSala(){
    return this->sala;
};


bool DtFuncion::isEqual(DtFuncion* Funcion){
    return this->getID() == Funcion->getID();
};

 string DtFuncion::toString(){
     return "Funcion: " + Utils::aString(this->getID()) + " | "
     + this->sala.toString() + " | ";
 };


DtFuncion::~DtFuncion()
{
    //dtor
}
