#include "../../include/datatypes/DtFuncion.h"

DtFuncion::DtFuncion(){
    id = 0;
    nickName = "";
    comentario = "";
    esRespuestaDeID = 0;//ctor
}

DtFuncion::DtFuncion(int id, int asientosReservados, float precioEntrada){
    this->id = id;
    this->asientosReservados = asientosReservados;
    this->precioEntrada = precioEntrada;
};

int DtFuncion::getID(){
    return this->id;
};

string DtFuncion::getNickName(){
    return this->nickName;
};
string DtFuncion::getComentario(){
    return this->comentario;
};

int DtFuncion::getEsRespuestaDeID(){
    return this->esRespuestaDeID;
};

bool DtFuncion::isEqual(DtFuncion* Funcion){
    return this->getID() == funcion->getID();
};

 string DtFuncion::toString(){
     return "Datos de la funcion " + this->getID();
 };


DtFuncion::~DtFuncion()
{
    //dtor
}
