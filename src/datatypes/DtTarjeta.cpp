#include "../../include/datatypes/DtTarjeta.h"

DtTarjeta::DtTarjeta()
{


    //ctor
}

DtTarjeta::DtTarjeta(int id, float montoTotal){
    this->idTarjeta = id;
    this->montoTotal = montoTotal;
};




int DtTarjeta::getIdTarjeta(){
return this->idTarjeta;
}

DtTarjeta::~DtTarjeta()
{
    //dtor
}
