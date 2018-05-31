#include "../../include/datatypes/DtDebito.h"

DtDebito::DtDebito()
{
    //ctor
}

DtDebito:: DtDebito(string banco){
this->banco = banco;

}

string DtBanco:: getBanco(){
return this->banco;
}

float DtBanco:: getMontoTotal(){
return this->montoTotal;
}

DtDebito::~DtDebito()
{
    //dtor
}
