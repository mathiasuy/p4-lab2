#include "../../include/datatypes/DtReserva.h"
#include "../../include/datatypes/DtFuncion.h"
#include "../../include/Utils.h"

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
    return "Reserva: ID:" +
    Utils::aString(this->getID()) +
    "\nCantidad de asientos: " +
    Utils::aString(this->getCantAsientos())+
    "\nFuncion: " +
    "\n--------------" +
    this->funcion.toString() +
    string("\n--------------") +
    this->tarjeta.toString()+ "\nTarjeta: " + string("\n--------------") + this->tarjeta.toString() + string("\n--------------");
}
DtReserva::~DtReserva()
{
    //dtor
}
