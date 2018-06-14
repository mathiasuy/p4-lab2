#include "../../include/logica/Comentario.h"


int Comentario::idGlobal = 0;

Comentario::~Comentario()
{
    //dtor
}

void Comentario::setEsRespuestaDeID(int id){
    this->esRespuestaDeID = id;
};


void Comentario::setComentairo(string comentario){
    this->comentario = comentario;
};

string Comentario::getComentario(){
    return this->comentario;
};

string Comentario::getNickName(){
    return this->nickName;
};

int Comentario::getEsRespuestaDeID(){
    return this->esRespuestaDeID;
};

int Comentario::getID(){
    return this->id;
};

string Comentario::toString(){
    return this->getDt().toString();
};


bool Comentario::isEqual(Comentario* comentario){
    return this->getID() == comentario->getID();
};

Comentario::Comentario(string nickName, string comentario){
    this->id = ++idGlobal;
    this->nickName = nickName;
    this->setComentairo(comentario);
    this->esRespuestaDeID = -1;
};

Comentario::Comentario(string nickName, string comentario, int esRespuestaDeID){
    this->id = ++idGlobal;
    this->nickName = nickName;
    this->setComentairo(comentario);
    this->esRespuestaDeID = esRespuestaDeID;
};

DtComentario Comentario::getDt(){
    return DtComentario(this->getID(), this->getNickName(), this->getComentario(), this->getEsRespuestaDeID());
}
