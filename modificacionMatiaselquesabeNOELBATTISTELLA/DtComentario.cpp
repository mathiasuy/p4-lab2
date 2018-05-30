#include "../../include/datatypes/DtComentario.h"

DtComentario::DtComentario(string nickname, string comentario, int id)
    {
    this->id = id;
    this->comentario = comentario;
    this->nickname = nickname;
    this->esRespuestaDeId = -1; //NO ES RESPUESTA DE NADA, SETEAMOS EN -1, CONVENCION CON EL CAMARADA BATTISTELLA

    //ctor
    }

DtComentario::DtComentario(string nickname, string comentario, int id, int esRespuestaDeId)
    {
      this->nickname= nickname;
      this->comentario = comentario;
      this->id = id;
      this->esRespuestaDeId = esRespuestaDeId;

    }

string DtComentario::getComentario()
    {
        return this->comentario;
    }

string DtComentario::getNickname(){
        return this->nickname;
}

int DtComentario::getId() {
    return this->id;
}

int DtComentario::getEsRespuestaDeId(){
    return this->esRespuestaDeId;
}

bool DtComentario::isEqual(DtComentario dtComentario) {
    return (this->getId() == dtComentario->getId());
}

string DtComentario::toString(){
    return "Comentario: " + this->getComentario() + " id: " + Utils::aString(this->getID());
}
DtComentario::~DtComentario()
{
    //dtor
}
