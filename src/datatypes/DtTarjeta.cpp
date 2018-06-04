#include "../../include/datatypes/DtTarjeta.h"

DtTarjeta::DtTarjeta()
{


    //ctor
}

DtTarjeta::DtTarjeta(int id, float montoTotal){
    this->idTarjeta = id;
    this->montoTotal = montoTotal;
};


bool DtTarjeta:: isEqual(DtTarjeta *t){
    return this->getIdTarjeta() == t->getIdTarjeta();
}

float DtTarjeta::getMontoTotal(){
    return this->montoTotal;
};



int DtTarjeta::getIdTarjeta(){
return this->idTarjeta;
}

DtTarjeta::~DtTarjeta()
{
    //dtor
}
