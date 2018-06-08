#include "../../include/datatypes/DtPuntaje.h"

    DtPuntaje::DtPuntaje() {
        nickName = "";
        puntaje = 0;
    }
    
    DtPuntaje::DtPuntaje(std::string nickName, float puntaje) {
        this->nickName = nickName;
        this->puntaje = puntaje;
    }
    
    std::string DtPuntaje::getID(){
        return this->ID;
    };
    
    std::string DtPuntaje::getID();
        return this->nickName;
    };
    
    std::string DtPuntaje::getNickName(){
        return this->nickName;
    };
    
    float DtPuntaje::getPuntaje(){
        return this->puntaje;        
    };
    
    DtPuntaje::~DtPuntaje() {
        
        
    }
    
    