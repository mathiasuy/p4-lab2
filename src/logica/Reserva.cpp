#include "../../include/logica/Reserva.h"
#include "../../include/logica/Credito.h"
#include "../../include/logica/Debito.h"



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

void Reserva::setCantAsientos(int cantAsientos){
    this->cantAsientos = cantAsientos;
};

bool Reserva::isEqual(Reserva * reserva){
    return this->getID() == reserva->getID();
};

std::string Reserva::toString(){
    return "Reserva n� "+ this->getID();
};

//Reserva::~Reserva(){}


Reserva::Reserva(int cantAsientos, Funcion* funcion, string financiera, float descuento, float montoTotal){
    this->id = ++idGlobal;
    this->setFuncion(funcion);
    Credito* c = new Credito(montoTotal,financiera,descuento);
    this->tarjeta =c;
    this->setCantAsientos(cantAsientos);
    this->setFuncion(funcion);
};

Reserva::Reserva(int cantAsientos, Funcion* funcion, string  banco, float montoTotal){
    this->id = ++idGlobal;
    this->setFuncion(funcion);
    Debito* d = new Debito(montoTotal,banco);
    this->tarjeta = d;
    this->setCantAsientos(cantAsientos);
    this->setFuncion(funcion);
};
