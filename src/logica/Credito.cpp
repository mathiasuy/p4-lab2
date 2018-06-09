#include "../../include/logica/Credito.h"



void Credito::setFinanciera(string financiera){
    this->financiera = financiera;
};

void Credito::setDescuento (float descuento){
    this->descuento = descuento;
};

string Credito::getFinanciera(){
    return this->financiera;
};

float Credito::getDescuento(){
    return this->descuento;
};

Credito::Credito(float monto, string financiera, float descuento):Tarjeta(monto){
    this->setFinanciera(financiera);
    this->setDescuento(descuento);
};

string Credito::toString(){
    return "Esta es la tarjeta de credito ";
};

Credito::~Credito(){

};

DtTarjeta Credito::getDt(){
    return DtCredito(this->getMonto(),this->financiera,this->descuento);
}



float Credito::getMonto(){
    return this->monto*DESCUENTO_FINANCIERA/100;
};
