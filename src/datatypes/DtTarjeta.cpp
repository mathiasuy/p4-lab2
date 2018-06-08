#include "../../include/datatypes/DtTarjeta.h"

DtTarjeta::DtTarjeta(){
    idTarjeta = 0;
    montoTotal = 0;
    //ctor
}

DtTarjeta::DtTarjeta(int id, float montoTotal){
    this->idTarjeta = id;
    this->montoTotal = montoTotal;
};

float DtTarjeta::getMontoTotal(){
    return this->montoTotal;
};

DtTarjeta::~DtTarjeta()
{
    //dtor
}
