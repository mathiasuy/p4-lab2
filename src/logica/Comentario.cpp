#include "../../include/logica/Comentario.h"
#include "Utils.h"

Comentario::~Comentario()
{
    //dtor
}

void Comentario::setEsRespuestaDeId(int id){
    this->esRespuestaDeId = id;
};


void Comentario::setComentairo(string comentario){
    this->comentario = comentario;
};

string Comentario::getComentario(){
    return this->comentario;
};

int Comentario::getEsRespuestaDeId(){
    return this->esRespuestaDeId;
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

Comentario::Comentario(int id, string nickName, string comentario){
    this->id = id;
    this->nickName = nickName;
    this->setComentairo(comentario);
};

Comentario::Comentario(int id, string nickName, string comentario, int esRespuestaDeId):Comentario(id,nickName,comentario){
    this->esRespuestaDeId = esRespuestaDeId;
};
