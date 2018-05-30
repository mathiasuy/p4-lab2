#include "../../include/datatypes/DtCredito.h"

DtCredito::DtCredito()
{
    //ctor
}

DtCredito::DtCredito(string financiera, float descuento){
this->financiera = financiera;
this->descuento = descuento;
};

string DtCredito::getFinanciera(){
return this->financiera;
}

bool DtCredito:: isEqual(DtTarjeta *t){
return true;
}

float DtCredito:: getDescuento(){
return this->descuento; }

float DtCredito:: getMontoTotal(float precio){
float res = (this->descuento * precio) / 100

}

DtCredito::~DtCredito()
{
    //dtor
}
