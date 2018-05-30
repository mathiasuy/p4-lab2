#include "../../include/logica/Cine.h"
#include "../Utils.h"

Cine::Cine(int id)
{
    this->id = id;
    this->setDireccion("N/D");
    this->setPrecioEntrada(0);
}

Cine::Cine(int id, string direccion, float precioEntrada)
{
    this->id = id;
    this->setDireccion(direccion);
    this->setPrecioEntrada(precioEntrada);
}

Cine::~Cine()
{
    // DESTRUIR SALAS
}

int Cine::getId(){
    return this->id;
}

string Cine::getDireccion(){
    return this->direccion;
};

float Cine::getPrecioEntrada(){
    return this->precioEntrada;
};

void Cine::setDireccion(string direccion){
    this->direccion = direccion;
}

void Cine::setPrecioEntrada(float precioEntrada){
    this->precioEntrada = precioEntrada;
}

string Cine::toString(){
    return "Cine: " + Utils::aString(this->getId()) + " " + this->getDireccion() + " " + Utils::aString(this->getPrecioEntrada());
};


bool Cine::isEqual(Cine *cine){
    return this->getId() == cine->getId();
}

/*
bool operator==( Cine& c1,  Cine& c2)
{
    c1.isEqual( c2 ) && c1.getId() == c2.getId();
}
*/
