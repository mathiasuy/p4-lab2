#include "../../include/logica/Funcion.h"

int Funcion::idGlobal = 0;

int Funcion::getID(){
    return this->id;
};


DtFecha Funcion::getFecha(){
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

void Funcion::setPelicula(Pelicula* pelicula){
    this->pelicula = pelicula;
};

void Funcion::setSala(Sala* sala){
    this->sala = sala;
};



string Funcion::toString(){
    return "Esta es la funcion: " + this->getID();
};

bool Funcion::isEqual(Funcion* funcion){
    return this->getID() == funcion->getID();
};


Funcion::Funcion(float precioEntrada, DtFecha fecha, Sala* sala , Pelicula *pelicula){
    this->asientosReservados = 0;
    this->id = ++idGlobal;
    this->precioEntrada = precioEntrada;
    this->setFecha(fecha);
    this->setPelicula(pelicula);
    this->setSala(sala);
};

int Funcion::getAsientosReservados(){
    this->asientosReservados;
};

int Funcion::getAsientosLibres(){
    return this->getSala()->getCapacidad() - this->getAsientosReservados();
}

Sala* Funcion::getSala()
{
    return this->sala;
}
void Funcion::agregarAsientosReservados(int aumento){
    this->asientosReservados+= aumento;
};

Funcion::~Funcion(){

};
