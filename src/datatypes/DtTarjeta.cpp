#include "../../include/datatypes/DtTarjeta.h"

DtTarjeta::DtTarjeta(){
    idTarjeta = 0;
    montoTotal = 0;
    //ctor
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
