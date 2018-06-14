#include "../../include/datatypes/DtDebito.h"


DtDebito:: DtDebito(float monto,string banco):DtTarjeta(monto){
    this->banco = banco;
}

DtDebito::DtDebito():DtTarjeta(){
    banco = "";
};

string DtDebito::getBanco(){
    return this->banco;
};

string DtDebito::toString(){
    return DtTarjeta::toString() +  " (debito) del banco: " + this->getBanco();
}

DtDebito::~DtDebito()
{
    //dtor
}
