#include "../../include/logica/Funcion.h"

int Funcion::getId(){
    return this->id;
};


DtFecha* Funcion::getFecha(){
    return this->fehca;
};


void Funcion::setFecha(DtFecha fecha){

};

string Funcion::toString(){
    return "Esta es la funcion: " + this->getId();
};

bool Funcion::isEqual(Funcion* funcion){
    return this->getId() == funcion->getId();
};


Funcion::Funcion(int id, DtSala* , DtCine* , DtFecha* ){
    this->id = id;
    this->setDtCine(cine);
    this->setDtSala(sala);
    this->setFecha(fecha);
};

Funcion::~Funcion(){

};
