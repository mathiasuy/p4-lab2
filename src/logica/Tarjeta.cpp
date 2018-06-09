#include "../../include/logica/Tarjeta.h"


Tarjeta::~Tarjeta()
{
    //dtor
}


float Tarjeta::getMonto(){
    return this->monto;
};

void Tarjeta::setMonto(float monto){
    this->monto= monto;
};


Tarjeta::Tarjeta(float monto){
    this->setMonto(monto);
};

string Tarjeta::toString(){
    return "Tarjeta: bal bla bal";
}
