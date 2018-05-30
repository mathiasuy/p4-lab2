#include "../../include/datatypes/DtCine.h"

        DtCine::~DtCine(){}

        int DtCine::getID(){
            return this->id;
        };

        string DtCine::getDireccion(){
            return this->direccion;
        };

        float DtCine::getPrecioEntrada(){
            return this->precioEntrada;
        };

        bool DtCine::isEqual(DtCine dtCine){
             return this->getID() == dtCine.getID();
        };

        string DtCine::toString(){
            return "Datos del cine " + this->getID();
        };

        DtCine::DtCine(int id, string direccion, float precioEntrada, vector<DtSala> salas){
            this->id = id;
            this->direccion = direccion;
            this->precioEntrada = precioEntrada;
            this->salas = salas;
        };
