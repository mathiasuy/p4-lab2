#include "../../include/datatypes/DtSala.h"
#include "../../include/Utils.h"

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


DtCine DtSala::getCine(){
    return this->cine;
};


string DtSala::toString(){
   return "Sala: " + Utils::aString(this->getID()) + " | "
   + "Cantidad de Asientos: " + Utils::aString(this->getCantAsientos()) + " | "
   + this->cine.toString();
};


DtSala::~DtSala()
{
    //dtor
}
