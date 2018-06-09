#include "../../include/logica/Reserva.h"


Reserva::~Reserva()
{
    this->funcion = NULL;
    delete this->tarjeta;
}

int Reserva::getID(){
    return id;
};

int Reserva::getCantAsientos(){
    return this->cantAsientos;
};

void Reserva::setCantAsientos(int cantAsientos){
    this->cantAsientos = cantAsientos;
};

bool Reserva::isEqual(Reserva * reserva){
    return this->getID() == reserva->getID();
};

void Reserva::setFuncion(Funcion* funcion){
    this->funcion = funcion;
};

std::string Reserva::toString(){
    return "Reserva n� "+ this->getID();
};

//Reserva::~Reserva(){}


Funcion* Reserva::getFuncion(){
    return this->funcion;
}

Reserva::Reserva(int cantAsientos, Funcion* funcion, string financiera, float descuento, float montoTotal){
    this->id = ++idGlobal;
    this->setFuncion(funcion);
    Credito* c = new Credito(montoTotal,financiera,descuento);
    this->tarjeta =c;
    this->setCantAsientos(cantAsientos);
    this->setFuncion(funcion);
    funcion->agregarAsientosReservados(cantAsientos);
};

Reserva::Reserva(int cantAsientos, Funcion* funcion, string  banco, float montoTotal){
    this->id = ++idGlobal;
    this->setFuncion(funcion);
    Debito* d = new Debito(montoTotal,banco);
    this->tarjeta = d;
    this->setCantAsientos(cantAsientos);
    this->setFuncion(funcion);
    funcion->agregarAsientosReservados(cantAsientos);
};


bool Reserva::tieneFuncion(int id){
    return this->funcion->getID() == id;
}

DtReserva Reserva::getDt(){
    DtTarjeta t = this->tarjeta->getDt();
    DtFuncion f = this->funcion->getDt();
    return DtReserva(this->getID(), this->cantAsientos, t, f );
};
