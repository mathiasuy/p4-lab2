#include "../../include/logica/Reserva.h"


Reserva::~Reserva()
{
    //dtor
}

int Reserva::getID(){
    return id;
};

int Reserva::getCantAsientos(){
    return this->cantAsientos;
};

DtFuncion Reserva::getDtFuncion(){
    return this->dtFuncion;
};

DtPelicula Reserva::getDtPelicula(){
    return this->dtPelicula;
};

Pago* Reserva::getPago(){
    return this->pago;
};

void Reserva::setCantAsientos(int cantAsientos){
    this->cantAsientos = cantAsientos;
};

void Reserva::setDtFuncion(DtFuncion funcion){
    this->dtFuncion = funcion;
};


void Reserva::setDtPelicula(DtPelicula pelicula){
    this->dtPelicula = pelicula;
};

void Reserva::setPago(Pago* pago){
    this->pago = pago;
};

bool Reserva::isEqual(Reserva * reserva){
    return this->getID() == reserva->getID();
};

string Reserva::toString(){
    return "Reserva n° "+ this->getID();
};

Reserva::~Reserva();

Reserva::Reserva(int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula){
    this->id = id;
    this->setCantAsientos(cantAsientos);
    this->setDtFuncion(funcion);
    this->setDtPelicula(pelicula);
};

Reserva::Reserva(int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, Pago* pago):Reserva(id,cantAsientos,funcion,pelicula){
    this->setPago(pago);
}
