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

    string TipoT = "Debito";
    if ( dynamic_cast<DtCredito*> (&this->tarjeta) != NULL){
            TipoT = "Credito";
    }

    return "Reserva: " + Utils::aString(this->getID()) +" | "
    + "Pelicula: " + this->funcion.getPelicula().getTitulo() +" | "
    + "Fecha de funcion: " +this->funcion.getFecha().toString() + " | "
    + "Asientos: " + Utils::aString(this->getCantAsientos()) +" | "
    + this->tarjeta.toString() + " | " + "Tipo tarjeta: "+ TipoT +" | "
    + "Cine: " + this->funcion->getSala()->getCine().getID();
}
DtReserva::~DtReserva()
{
    //dtor
}
