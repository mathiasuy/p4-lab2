#include "../../include/datatypes/DtSala.h"

DtSala::DtSala(){
    this->cantAsientos = 0;
    this->idSala = 0;
};

DtSala::DtSala(int idSala, int cantAsientos)
{
    this->cantAsientos = cantAsientos;
    this->idSala = idSala;
};

int DtSala::getID(){
    return this->idSala;
};

int DtSala::getCantAsientos(){
    return this->cantAsientos;
};

DtSala::~DtSala()
{
    //dtor
}
