#include "../../include/datatypes/DtCine.h"
#include "../../include/Utils.h"



        DtCine::DtCine(){
            this->id = 0;
            this->direccion = "";
        };

        DtCine::DtCine(int id, string direccion){
            this->id = id;
            this->direccion = direccion;
        };

        int DtCine::getID(){
            return this->id;
        };

        string DtCine::getDireccion(){
            return this->direccion;
        };

        bool DtCine::isEqual(DtCine dtCine){
             return this->getID() == dtCine.getID();
        };

        DtCine::~DtCine(){
        }

        string DtCine::toString(){
            return  "Cine: " + Utils::aString(this->getID()) + " | "
            + "Direcccion: " + this->getDireccion();
        };

