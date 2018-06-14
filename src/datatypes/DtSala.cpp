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

string DtSala::toString(){
   return "Sala: ID: S" + Utils::aString(this->getID()) + " \nCantidad de asientos: " + Utils::aString(this->getCantAsientos()) + "\nDireccion: " + this->cine.getDireccion();
};


DtSala::~DtSala()
{
    //dtor
}
