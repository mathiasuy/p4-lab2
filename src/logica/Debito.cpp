#include "../../include/logica/Debito.h"
#include "include/datatypes/DtDebito.h"


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

Debito::Debito(float montoTotal, string banco):Tarjeta(montoTotal){
    this->setBanco(banco);
};

DtTarjeta Debito::getDt(){
    return DtDebito(this->getMontoTotal(),this->banco);
};