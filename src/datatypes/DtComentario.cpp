
#include "../../include/datatypes/DtComentario.h"
#include "../../include/Utils.h"
#include <iostream>

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

        void DtComentario::setNickName(string nickName){
            this->nickName = nickName;
        };

        void DtComentario::setComentario(string comentario){
            this->comentario = comentario;
        };

        void DtComentario::setEsRespuestaDeID(int esRespuestaDeID){
            this->esRespuestaDeID = esRespuestaDeID;
        };

        bool DtComentario::isEqual(DtComentario* comentario){
            return this->getID() == comentario->getID();
        };
        DtComentario::DtComentario(int id, string nickName, string comentario){
            this->id = id;
            this->nickName = nickName;
            this->comentario = comentario;
            this->esRespuestaDeID = -1;
        };

        DtComentario::DtComentario(int id, string nickName, string comentario, int esRespuestaDeID){
            this->id = id;
            this->nickName = nickName;
            this->comentario = comentario;
            this->esRespuestaDeID = esRespuestaDeID;
        };
        DtComentario::~DtComentario(){

        };

        DtComentario::DtComentario(){

        };

        string DtComentario::toString(){
            string retornar;
//            cout << "llego 1" << endl;
              retornar = Utils::aString(this->getID()) + ": " + this->getNickName() + ":" + this->getComentario();
//            cout << "llego 2" << endl;
            return retornar;
        };
