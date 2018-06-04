#include "../../include/datatypes/DtDebito.h"


DtDebito:: DtDebito(int idTarjeta, float monto,string banco):DtTarjeta(idTarjeta, monto){
    this->banco = banco;
}

DtDebito::~DtDebito()
{
    //dtor
}

string DtDebito::toString(){
    return "DtDebito";
}
