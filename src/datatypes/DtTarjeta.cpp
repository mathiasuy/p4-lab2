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

int DtTarjeta::getIdTarjeta(){
    return this->idTarjeta;
}

float DtTarjeta::getMontoTotal(){
    return this->montoTotal;
};

bool DtTarjeta:: isEqual(DtTarjeta *t){
    return this->getIdTarjeta() == t->getIdTarjeta();
}

DtTarjeta::~DtTarjeta()
{
    //dtor
}
