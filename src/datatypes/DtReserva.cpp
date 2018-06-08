#include "../../include/datatypes/DtReserva.h"

DtReserva::DtReserva(){
    this->id = 0;
    this->cantAsientos = 0 ;
    //ctor
}

DtReserva::DtReserva(int id, int cantAsientos){
    this->id = id;
    this->cantAsientos = cantAsientos;

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
    return "Datos de la reserva " + this->getID();
}
DtReserva::~DtReserva()
{
    //dtor
}
