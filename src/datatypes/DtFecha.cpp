#include "../../include/datatypes/DtFecha.h"


DtFecha DtFecha::getFechaActual() {
    time_t now = std::time(0);
    tm *ltm = localtime(&now);
    return DtFecha(1 + ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year,0,0);
}

DtFecha::DtFecha() //CONSTRUCTOR HORA ACTUAL
{
    //DtFecha temporal;
    //temporal.getFechaActual();
    this->dia = 10;//ctor
    this->mes = 11;
    this->ano = 12;
    this->hora = 13;
    this->minuto = 14;
}

DtFecha::DtFecha(int dia, int mes, int ano, int minuto, int hora)
{
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
  this->minuto = minuto;
  this->hora = hora;  //ctor
}

int DtFecha::getAno() {
    return this->ano;
}

int DtFecha::getDia() {
    return this->dia;
}


int DtFecha::getHora(){
    return this->hora;
}

int DtFecha::getMes() {
    return this->mes;
}

int DtFecha::getMinuto(){
    return this->minuto;
}

string DtFecha::toString(){
    return "DD/MM/AA - 00:00";
}


DtFecha::~DtFecha()
{
    //dtor
}
