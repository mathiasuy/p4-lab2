#include "../../include/logica/Pago.h"


Pago::~Pago()
{
    //dtor
}

float Pago::getMonto(){
    return this->monto;
};

Tarjeta* Pago::getTarjeta(){
    return this->tarjeta;
};

void Pago::setMonto(float monto){
    this->monto = monto;
};

void Pago::setTarjeta (Tarjeta* tarjeta){
    this->tarjeta = tarjeta;
};

Pago::Pago(int id, float monto, Tarjeta* tarjeta){
    this->id = id;
    this->setMonto(monto);
    this->setTarjeta(tarjeta);
};

int Pago::getID(){
    return this->getID();
}

bool Pago::isEqual(Pago* pago){
    return pago->getID() == this->getID();
}

string Pago::toString(){
    return "Este es el pago n° " + this->getID();
}
