
#include "../../include/datatypes/DtComentario.h"

        int DtComentario::getID(){
            return this->id;
        };
        string DtComentario::getNickName(){
            return this->nickName;
        };
        string DtComentario::getComentario(){
            return this->comentario;
        };
        int DtComentario::getEsRespuestaDeID(){
            return this->esRespuestaDeID;
        };
        bool DtComentario::isEqual(DtComentario* comentario){
            return this->getID() == comentario->getID();
        };
        DtComentario::DtComentario(string nickName, string comentario){
            this->nickName = nickName;
            this->comentario = comentario;
            this->esRespuestaDeID = -1;
        };
        DtComentario::DtComentario(string nickName, string comentario, int esRespuestaDeID){
            this->nickName = nickName;
            this->comentario = comentario;
            this->esRespuestaDeID = esRespuestaDeID;
        };
        DtComentario::~DtComentario(){

        };
