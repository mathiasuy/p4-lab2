#include "../../include/datatypes/DtSala.h"

DtSala::DtSala(){
    this->cantAsientos = 0;
    this->idSala = 0;
};

DtSala::DtSala(int idSala, int cantAsientos, DtCine cine)
{
    this->cine = cine;
    this->cantAsientos = cantAsientos;
    this->idSala = idSala;
};

int DtSala::getID(){
    return this->idSala;
};

int DtSala::getCantAsientos(){
    return this->cantAsientos;
};

string toString(){
   return "Datos de la sala " + this->getID() + ": " + this->getCantAsientos() + this->cine->toString();
};


DtSala::~DtSala()
{
    //dtor
}
