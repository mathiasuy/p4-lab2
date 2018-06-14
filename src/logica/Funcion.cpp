#include "../../include/logica/Funcion.h"
#include <iostream>
#include "../../include/logica/Pelicula.h"
#include "../../include/logica/Sala.h"

int Funcion::idGlobal = 0;

int Funcion::getID(){
    return this->id;
};


DtFecha Funcion::getFecha(){
    return this->fecha;
};

float Funcion::getPrecio(){
    return this->precioEntrada;

};


DtFuncion Funcion::getDt(){
    DtPelicula p;
    return DtFuncion(this->id,this->asientosReservados,this->precioEntrada,this->sala->getDt(),this->pelicula->getDt());
};

void Funcion::setFecha(DtFecha fecha){
    this->fecha = fecha;
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
    return "Esta es la funcion: " + Utils::aString(this->getID());
};

bool Funcion::isEqual(Funcion* funcion){
    return this->getID() == funcion->getID();
};


Funcion::Funcion(float precioEntrada, DtFecha fecha, Sala* sala , Pelicula *pelicula){
    this->asientosReservados = 0;

    this->id = ++idGlobal;
    //cout << "ID DE LA FUNC: " << Utils::aString(this->id);
    this->precioEntrada = precioEntrada;
    this->setFecha(fecha);
    this->setPelicula(pelicula);
    this->setSala(sala);
};

int Funcion::getAsientosReservados(){
    return this->asientosReservados;
};

int Funcion::getAsientosLibres(){
    return (this->sala->getCapacidad() - this->getAsientosReservados());
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
