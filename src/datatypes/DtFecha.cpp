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

DtFecha::DtFecha(int dia, int mes, int ano, int hora, int minuto)
{
  this->dia = dia;
  this->mes = mes;
  this->ano = ano;
  this->minuto = minuto;
  this->hora = hora;  //ctor
}

bool DtFecha::operator <(const DtFecha& f){
    	bool retorno = false;
    	if (this->ano < f.ano){
    		retorno = true;
    	}else if (this->ano > f.ano){
    		retorno = false;
    	}else{
    		if (this->mes < f.mes){
    			retorno = true;
    		}else if (this->mes > f.mes){
    			retorno = false;
    		}else{
    			if (this->dia < f.dia){
    				retorno = true;
    			}else if(this->dia > f.dia){
    				retorno = false;
    			}else{
                     if (this->hora < f.hora){
                            retorno = true;
                        }else if(this->hora > f.hora){
                            retorno = false;
                        }else{
                            if (this->minuto < f.minuto){
                                retorno = true;
                            }else if(this->minuto > f.minuto){
                                retorno = false;
                            }else
                                retorno = false;
                              }
                    }
                }
            }
        return retorno;
};

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
    return     Utils::aString(this->dia)     + "/"
    + Utils::aString(this->mes)     + "/"
    + Utils::aString(this->ano)     + " "
    + Utils::aString(this->hora)    + ":"
    + Utils::aString(this->minuto);
}


DtFecha::~DtFecha()
{
    //dtor
}
