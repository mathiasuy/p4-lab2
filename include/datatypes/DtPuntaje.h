/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DtPuntaje.h
 * Author: user6
 *
 * Created on 3 de junio de 2018, 04:29 AM
 */

#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H
#include <string>

class DtPuntaje {
private:
        std::string nickName;
        float puntaje;
public:
        std::string getID();
    std::string getNickName();
    float getPuntaje();
    DtPuntaje();
    DtPuntaje(std::string nickName, float puntaje);
    virtual ~DtPuntaje();
};

#endif /* DTPUNTAJE_H */

