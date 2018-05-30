#include "../../include/logica/Tarjeta.h"


Tarjeta::~Tarjeta()
{
    //dtor
}

bool Tarjeta::isEqual(Tarjeta* t)
{
    return true;
}

int Tarjeta::getID(){
    return this->id;
}

float Tarjeta::getMontoTotal(){
    return this->montoTotal;
};

void Tarjeta::setMontoTotal(float montoTotal){
    this->montoTotal= montoTotal;
};


Tarjeta::Tarjeta(int id, float montoTotal){
    this->id = id;
    this->setMontoTotal(montoTotal);
};
