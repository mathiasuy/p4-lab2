#include "../../include/datatypes/DtCredito.h"
#include "../../include/Utils.h"

DtCredito::DtCredito(float monto, string financiera, float descuento):DtTarjeta(monto){
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
    return DtTarjeta::toString() + " (credito) \nDescuento: " + Utils::aString(this->getDescuento()) + " de la financiera: " + this->getFinanciera();
}

DtCredito::~DtCredito()
{
    //dtor
}
