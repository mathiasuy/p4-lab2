#include "../../include/logica/Debito.h"


Debito::~Debito()
{
    //dtor
}

void Debito::setBanco(string banco){
    this->banco = banco;
};

string Debito::getBanco(){
    return this->banco;
};

string Debito::toString(){
    return "Esta es la tarjeta de debito ";
};

Debito::Debito(float monto, string banco):Tarjeta(monto){
    this->setBanco(banco);
};

DtTarjeta Debito::getDt(){
    return DtDebito(this->getMonto(),this->banco);
};


float Debito::getMonto(){
    return this->monto;
};
