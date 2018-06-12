#include "../../include/logica/Sala.h"
#include "../../include/logica/Cine.h"
#include <iostream>



int Sala::getID(){
    return this->id;
};

void Sala::setID(int id){
    this->id = id;
};


int Sala::getCapacidad(){
    return capacidad;
};

void Sala::setCapacidad(int capacidad){
    this->capacidad = capacidad;
};

bool Sala::agregarFuncion(Funcion* funcion){
//agrego puntero hacia funcion en el map con la clave igual al idfuncion

    this->funciones[funcion->getID()] = funcion;
    return true;
};

bool Sala::quitarFuncion(Funcion* funcion){
//quitar puntero de funcion del map
    return this->funciones.erase(funcion->getID());

};

bool Sala::isEqual(Sala* sala){
    return this->getID() == sala->getID();
};

DtSala Sala::getDt(){
    Cine* cine = this->getCine();
    return DtSala(this->getID(),this->getCapacidad(), cine->getDt());
};

bool Sala::perteneceA(Cine* cine){
    return this->cine->isEqual(cine);
}

string Sala::toString(){
    //cout << "\nID Sala: _" << this->getID() << "_\n" ;
    return "Esta es la sala " + Utils::aString(this->getID());// + Utils::aString(this->getID());
};


Cine* Sala::getCine(){
    return this->cine;
};

Sala::Sala(int id, int capacidad, Cine* cine){
    this->id = id;
    this->cine = cine;
    this->setCapacidad(capacidad);

    //creo map de punteros
    std::map<int, Funcion*> mymap;
    this->funciones = mymap;
};

Sala::~Sala(){};


bool Sala::tieneFuncion(int id){
    return this->funciones.find(id) != this->funciones.end();
}

bool Sala::esDeCine(int idCine){
    return this->getCine()->getID() == idCine;
};
