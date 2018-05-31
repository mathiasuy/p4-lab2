#include "../../include/datatypes/DtFecha.h"

DtFecha::DtFecha() //CONSTRUCTOR HORA ACTUAL
{
    DtFecha temporal;
    temporal->getFechaActual();
    this->dia = temporal->getDia();//ctor
    this->mes = temporal->getMes();
    this->anio = temporal->getAnio();
    this->hora = 0;
    this->minuto = 0;
}

DtFecha::DtFecha(int dia, int mes, int anio, int minuto, int hora)
{
  this->dia = dia;
  this->mes = mes;
  this->anio = anio;
  this->minuto = minuto;
  this->hora = hora;  //ctor
}

int DtFecha::getAnio() {
    return this->anio;
}

int DtFecha::getDia() {
    return this->dia;
}

DtFecha DtFecha::getFechaActual() {

    time_t now = std::time(0);
    tm *ltm = localtime(&now);
    return DtFecha(1 + ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);

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



DtFecha::~DtFecha()
{
    //dtor
}