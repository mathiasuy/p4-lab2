#include "../../include/datatypes/DtDebito.h"


DtDebito:: DtDebito(int idTarjeta, float monto,string banco):DtTarjeta(idTarjeta, monto){
    this->banco = banco;
}

DtDebito::DtDebito():DtTarjeta(){
    banco = "";
};

string DtDebito::getBanco(){
    return this->banco;
};

bool DtDebito::isEqual(DtDebito* t){
    return this->banco == DtDebito.getBanco(t);
};


string DtDebito::toString(){
    return "DtDebito";
}

DtDebito::~DtDebito()
{
    //dtor
}