#include "../../include/datatypes/DtPuntaje.h"

    DtPuntaje::DtPuntaje() {
        nickName = "";
        puntaje = 0;
    };
    
    DtPuntaje::DtPuntaje(string nickName, float puntaje){
        this->nickName = nickName;
        this->puntaje = puntaje;
    };
    
    string DtPuntaje::getID(){
        return this->nickName;
    };
    
    string DtPuntaje::getNickName(){
        return this->nickName;
    };
    
    float DtPuntaje::getPuntaje(){
        return this->puntaje;        
    };
    
    string DtPuntaje::toString(){
        return "Puntaje: " + this->getPuntaje();
    };
    
    DtPuntaje::~DtPuntaje() {
    }
    
    