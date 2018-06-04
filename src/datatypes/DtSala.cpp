#include "../../include/datatypes/DtSala.h"

DtSala::DtSala(int idSala, int cantAsientos)
{
    this->cantAsientos = cantAsientos;
    this->idSala = idSala;
}

DtSala::~DtSala()
{
    //dtor
}
