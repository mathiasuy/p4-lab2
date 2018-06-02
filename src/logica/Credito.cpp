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

Credito::Credito(float montoTotal, string financiera, float descuento):Tarjeta(montoTotal){
    this->setFinanciera(financiera);
    this->setDescuento(descuento);
};

bool Credito::isEqual(Tarjeta * t){
    return this->getID() == t->getID();
};
string Credito::toString(){
    return "Esta es la tarjeta de credito " + this->getID();
};

Credito::~Credito(){

};
