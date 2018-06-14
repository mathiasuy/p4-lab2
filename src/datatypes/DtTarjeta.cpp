#include "../../include/datatypes/DtTarjeta.h"
#include "../../include/Utils.h"

DtTarjeta::DtTarjeta(){
    montoTotal = 0;
}

DtTarjeta::DtTarjeta(float montoTotal){
    this->montoTotal = montoTotal;
};

float DtTarjeta::getMontoTotal(){
    return this->montoTotal;
};

DtTarjeta::~DtTarjeta()
{
    //dtor
}

string DtTarjeta::toString(){
    return "Monto total $" + Utils::aString(this->getMontoTotal());
};
