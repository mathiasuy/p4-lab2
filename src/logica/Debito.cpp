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

bool Debito::isEqual(Tarjeta * t){
    return this->getID() == t->getID();
};

string Debito::toString(){
    return "Esta es la tarjeta de debito " + this->getID();
};

Debito::Debito(int id, float montoTotal, string banco):Tarjeta(id,montoTotal){
    this->setBanco(banco);
};
