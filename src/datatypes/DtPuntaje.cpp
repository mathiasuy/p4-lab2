/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DtPuntaje.cpp
 * Author: user6
 * 
 * Created on 3 de junio de 2018, 04:29 AM
 */

#include "../../include/datatypes/DtPuntaje.h"

DtPuntaje::DtPuntaje(std::string nickName, float puntaje) {
    this->nickName = nickName;
    this->puntaje = puntaje;
}


DtPuntaje::~DtPuntaje() {
}

    std::string DtPuntaje::getNickName(){
        return this->nickName;
    };
    
    float DtPuntaje::getPuntaje(){
        return this->puntaje;        
    };