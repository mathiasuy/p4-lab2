#include "../../include/logica/Comentario.h"
#include "Utils.h"

#include "datatypes/DtComentario.h"

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

int Comentario::getEsRespuestaDeID(){
    return this->esRespuestaDeID;
};

int Comentario::getID(){
    return this->id;
};

string Comentario::toString(){
    return "Comentario: " + this->getComentario() + " id: " + Utils::aString(this->getID());
};


bool Comentario::isEqual(Comentario* comentario){
    return this->getID() == comentario->getID();
};

Comentario::Comentario(string nickName, string comentario){
    this->id = ++idGlobal;
    this->nickName = nickName;
    this->setComentairo(comentario);
};

Comentario::Comentario(string nickName, string comentario, int esRespuestaDeID){
    this->id = ++idGlobal;
    this->nickName = nickName;
    this->setComentairo(comentario);
    this->esRespuestaDeID = esRespuestaDeID;
};
