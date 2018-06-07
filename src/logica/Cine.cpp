#include "../../include/logica/Cine.h"



int Cine::idGlobal = 0;

Cine::Cine(string direccion, vector<int> salas)
{
    this->id = ++idGlobal;
    for (std::vector<int>::iterator it = salas.begin() ; it != salas.end(); ++it){
    	Sala* sala = new Sala(*it,this);
        this->salas[sala->getID()] = sala;
    }
    this->setDireccion(direccion);
}

ListaDt<int,DtSala> Cine::listarDtSalas(){
    map<int,Sala*>::iterator it = this->salas.begin();
    ListaDt<int,DtSala> dt;
    while(it != this->salas.end()){
        dt.add(it->second->getDtSala());
    }
    return dt;
};

DtCine Cine::getDtCine(){
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
