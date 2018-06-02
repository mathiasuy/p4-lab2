#include "../../include/logica/Funcion.h"

int Funcion::getID(){
    return this->id;
};


DtFecha* Funcion::getFecha(){
    return this->fehca;
};

float Funcion::getPrecio(){
    return this->precioEntrada;
    
};

void Funcion::setFecha(DtFecha fecha){
    this->fehca = fecha;
};

void Funcion::setPrecio(float precioEntrada){
    this->precioEntrada = precioEntrada;
};


string Funcion::toString(){
    return "Esta es la funcion: " + this->getId();
};

bool Funcion::isEqual(Funcion* funcion){
    return this->getId() == funcion->getId();
};


Funcion::Funcion(int asientosReservados, float precioEntrada, DtFecha fecha, Sala* sala , Pelicula *pelicula){
    this->id = ++idGlobal;
    this->precioEntrada = precioEntrada;
    this->setFecha(fecha);
    this->setPelicula(pelicula);
    this->setSala(sala);
};

Funcion::~Funcion(){

};
