#include "../../include/logica/Sala.h"
#include "../../include/logica/Funcion.h"
#include <map>


int Sala::getID(){
    return this->id;
};

int Sala::getCapacidad(){
    return capacidad;
};

void Sala::setCapacidad(int capacidad){
    this->capacidad = capacidad;
};

bool agregarFuncion(Funcion* funcion){
//agrego puntero hacia funcion en el map con la clave igual al idfuncion

    typedef pair<string, *funcion> componente;
    this->funciones.insert( componente(getidFuncion(funcion), funcion) ); //getidFuncion falta 
};
    
bool quitarFuncion(Funcion* funcion){
//quitar puntero de funcion del map
    this->funciones.erase( getidFuncion(funcion) );
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
    
    //creo map de punteros
    std::map<int, Funcion*> mymap;
    this->funciones = mymap;
};

Sala::~Sala(){};
