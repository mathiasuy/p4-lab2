#include "../../include/datatypes/DtCredito.h"

DtCredito::DtCredito(int idTarjeta, float montoTotal, string financiera, float descuento):DtTarjeta(idTarjeta,montoTotal){
    this->financiera = financiera;
    this->descuento = descuento;
};

DtCredito::DtCredito():DtTarjeta(){
    financiera ="";
    descuento = 0;
};

string DtCredito::getFinanciera(){
    return this->financiera;
}

float DtCredito:: getDescuento(){
    return this->descuento;
}

string DtCredito::toString(){
    return "credito";
}

DtCredito::~DtCredito()
{
    //dtor
}
