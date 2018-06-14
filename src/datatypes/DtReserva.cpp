#include "../../include/datatypes/DtReserva.h"
#include "../../include/datatypes/DtFuncion.h"

DtReserva::DtReserva(){
    this->id = 0;
    this->cantAsientos = 0 ;
    //ctor
}

DtReserva::DtReserva(int id, int cantAsientos, DtTarjeta tarjeta, DtFuncion funcion){
    this->id = id;
    this->cantAsientos = cantAsientos;
    this->tarjeta = tarjeta;
    this->funcion = funcion;
    //ctor
}

int DtReserva::getID(){
    return this->id;
}

int DtReserva:: getCantAsientos(){
    return this->cantAsientos;
}

bool DtReserva::isEqual(DtReserva* t){
    return this->getID() == t->getID();
};

string DtReserva::toString(){
    return "Datos de la reserva " + this->getID() + this->getCantAsientos() + this->funcion.getID() + this->tarjeta.toString();
}
DtReserva::~DtReserva()
{
    //dtor
}
