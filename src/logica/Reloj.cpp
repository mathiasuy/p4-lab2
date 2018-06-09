#include "../../include/logica/Reloj.h"

Reloj::Reloj() {
    this->dia = 0;
    this->mes= 1;
    this->anio= 2;
    this->hora= 3;
    this->minuto= 4;
}

Reloj* Reloj::r = NULL;

Reloj::Reloj(int dia, int mes, int anio, int hora, int minuto) {
    this->dia = dia;
    this->mes= mes;
    this->anio= anio;
    this->hora= hora;
    this->minuto= minuto;
}

Reloj* Reloj::getInstancia(){
    if (Reloj::r ==NULL){
        Reloj::r = new Reloj();
    }
    return Reloj::r;
}

void Reloj::setDia(int dia) {
    this->dia = dia;
}
void Reloj::setMes(int mes) {
    this->mes = mes;
}

void Reloj::setAnio(int anio) {
    this->anio = anio;
}

void Reloj::setHora(int hora) {
    this->hora = hora;
}

void Reloj::setMinuto(int minuto) {
    this->minuto = minuto;
}

int Reloj::getDia(){
    return this->dia;
}

int Reloj::getMes(){
    return this->mes;
}

int Reloj::getAnio(){
    return this->anio;
}
int Reloj::getHora(){
    return this->hora;
}

int Reloj::getMinuto(){
    return this->minuto;
}

DtFecha Reloj::getFechaActual() {
    return DtFecha(
    this->dia,
    this->mes,
    this->anio,
    this->hora,
    this->minuto
    );
}

std::string Reloj::toString(){
    return ""
    + Utils::aString(this->dia)     + "/"
    + Utils::aString(this->mes)     + "/"
    + Utils::aString(this->anio)     + " "
    + Utils::aString(this->hora)    + ":"
    + Utils::aString(this->minuto);
};

Reloj::~Reloj() {
}

