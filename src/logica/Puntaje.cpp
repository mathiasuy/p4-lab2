#include "../../include/logica/Puntaje.h"

    void Puntaje::setPuntaje(float puntaje){
        this->puntaje = puntaje;
    };

    float Puntaje::getPuntaje(){
        return this->getPuntaje();
    };

    string Puntaje::getNickName(){
        return this->getNickName();
    };

    string Puntaje::getId(){
        return this->getNickName();
    };

    string Puntaje::toString(){
        return "Este es el puntaje del usuario " + this->getNickName();
    };

    bool Puntaje::isEqual(Puntaje *puntaje){
        return this->getId() == puntaje->getId();
    };

    Puntaje::Puntaje(string nickName, float puntaje){
        this->nickName = nickName;
        this->setPuntaje(puntaje);
    }

    Puntaje::~Puntaje(){};
