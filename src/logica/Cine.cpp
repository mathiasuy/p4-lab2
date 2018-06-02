#include "../../include/logica/Cine.h"
#include "../Utils.h"


Cine::Cine(string direccion, vector<int> salas)
{
    this->id = ++idGlobal;
    for (std::vector<int>::iterator it = salas.begin() ; it != salas.end(); ++it){
    	Sala* sala = new Sala(*it);
        this->salas[sala->getID()] = salas;
    }
    this->setDireccion(direccion);
}

Cine::~Cine()
{
    map<int,Sala*>::iterator it;
    for (it = salas.begin(); it != salas.end(); ++it)
        delete it->second;
}

int Cine::getId(){
    return this->id;
}

string Cine::getDireccion(){
    return this->direccion;
};

void Cine::setDireccion(string direccion){
    this->direccion = direccion;
}

string Cine::toString(){
    return "Cine: " + Utils::aString(this->getId()) + " " + this->getDireccion() + " ";
};


bool Cine::tieneSala(int id){
    return (this->salas.find(id) != this->salas.end());
}

bool Cine::isEqual(Cine *cine){
    return this->getId() == cine->getId();
}

/*
bool operator==( Cine& c1,  Cine& c2)
{
    c1.isEqual( c2 ) && c1.getId() == c2.getId();
}
*/
