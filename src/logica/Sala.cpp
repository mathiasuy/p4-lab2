#include "../../include/logica/Sala.h"

int Sala::getID(){
    return this->id;
};

int Sala::getCapacidad(){
    return capacidad;
};

void Sala::setCapacidad(int capacidad){
    this->capacidad = capacidad;
};

bool Sala::isEqual(Sala* sala){
    return this->getID() == sala->getID();
};

string Sala::toString(){
    return "Esta es la sala " + this->getID();
};

Sala::Sala(int id, int capacidad){
    this->id = id;
    this->setCapacidad(capacidad);
};

Sala::~Sala(){};
