#include "../../include/logica/Puntaje.h"
#include "iostream"

    void Puntaje::setPuntaje(float puntaje){
        //cout << puntaje  << << "ES EL PUNT";
        this->puntaje = puntaje;
    };

    float Puntaje::getPuntaje(){
        return this->puntaje;
    };

    string Puntaje::getNickName(){
        return this->nickName;
    };

    string Puntaje::getID(){
        return this->nickName;
    };

    string Puntaje::toString(){
        return "Este es el puntaje del usuario " + this->getNickName();
    };

    bool Puntaje::isEqual(Puntaje *puntaje){
        return this->getID() == puntaje->getID();
    };

    Puntaje::Puntaje(string nickName, float puntaje){
        this->nickName = nickName;
        this->setPuntaje(puntaje);
    }

    Puntaje::~Puntaje(){};

    DtPuntaje Puntaje::getDt(){
        return DtPuntaje(this->getNickName(),this->getPuntaje());
    };
