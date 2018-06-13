#include "../../include/logica/Cine.h"
#include <iostream>

int Cine::idGlobal = 0;

Cine::Cine(string direccion, vector<int> salas)
{

    this->id = ++idGlobal;
//    cout << "Direccion; " << direccion;

    int j = 0;
    vector<int>::iterator it = salas.begin();
    while (it != salas.end()){
        //cout << "Capacidad de la sala n°" << j << " " << salas[j] << "\n";
    	Sala* sala = new Sala(++j,*it,this);
        this->salas[sala->getID()] = sala;
        //cout << this->salas[sala->getID()]->toString();
        it++;
    }
    this->setDireccion(direccion);
}

Util::ListaDt<int,DtSala> Cine::listarDtSalas(){
    Util::ListaDt<int,DtSala> dt;
    map<int, Sala*>::iterator it = salas.begin();
    while (it != salas.end()){
        dt.add(it->second->getDt());
        it++;
    }
    return dt;
};

DtCine Cine::getDt(){
    return DtCine(this->getID(),this->getDireccion());
}

Cine::~Cine()
{
    map<int,Sala*>::iterator it;
    for (it = salas.begin(); it != salas.end(); ++it)
        delete it->second;
}

int Cine::getID(){
    return this->id;
}

string Cine::getDireccion(){
    return this->direccion;
};

void Cine::setDireccion(string direccion){
    this->direccion = direccion;
}

string Cine::toString(){

    return "Cine: " + Utils::aString(this->getID()) + " " + this->getDireccion() + " ";
};



bool Cine::tieneSala(int id){
    return (this->salas.find(id) != this->salas.end());
}

bool Cine::isEqual(Cine *cine){
    return this->getID() == cine->getID();
}

Sala* Cine::getSala(const int id){
    return this->salas.find(id)->second;
}

/*
bool operator==( Cine& c1,  Cine& c2)
{
    c1.isEqual( c2 ) && c1.getID() == c2.getID();
}
*/
