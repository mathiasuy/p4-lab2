#include "../../include/datatypes/DtReserva.h"

DtReserva::DtReserva(){
    this->id = 0;
    this->cantAsientos = 0 ;
    //ctor
}

DtReserva::DtReserva(int id, int cantAsientos){
    this->id = id;
    this->cantAsientos = cantAsientos;
    
    //ctor
}

DtReserva::DtReserva(int id, int cantAsientos, string financiera, float montoTotal, float descuento){
    this->id = id;
    this->cantAsientos = cantAsientos;
    
};
  
DtReserva::DtReserva(int id, int cantAsientos, string  banco, float montoTotal){
    this->id = id;
    this->cantAsientos = cantAsientos;
    
};

int DtReserva::getID(){
    return this->id;
}

int DtReserva:: getCantAsientos(){
    return this->cantAsientos;
}

bool DtReserva::isEqual(DtReserva* t){
    return this->id == DtReserva.getID(t);
};

string DtCredito::toString(){
    return "Datos de la reserva " + this->getID();
}
DtReserva::~DtReserva()
{
    //dtor
}
