#include "../../include/datatypes/DtCredito.h"

DtCredito::DtCredito(int idTarjeta, float montoTotal, string financiera, float descuento):DtTarjeta(idTarjeta,montoTotal){
    this->financiera = financiera;
    this->descuento = descuento;
};

string DtCredito::getFinanciera(){
    return this->financiera;
}

float DtCredito:: getDescuento(){
    return this->descuento;
}

DtCredito::~DtCredito()
{
    //dtor
}

string DtCredito::toString(){
    return "credito";
}
