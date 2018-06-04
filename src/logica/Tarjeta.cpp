#include "../../include/logica/Tarjeta.h"


Tarjeta::~Tarjeta()
{
    //dtor
}


float Tarjeta::getMontoTotal(){
    return this->montoTotal;
};

void Tarjeta::setMontoTotal(float montoTotal){
    this->montoTotal= montoTotal;
};


Tarjeta::Tarjeta(float montoTotal){
    this->setMontoTotal(montoTotal);
};
