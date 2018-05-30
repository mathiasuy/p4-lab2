#include "../../include/manejadores/ManejadorFunciones.h"

        ManejadorFunciones* ManejadorFunciones::instancia = NULL;
        map<int, Funcion*> funciones;

        ManejadorFunciones::ManejadorFunciones(){}


        /*  OPERACIONES */
        ManejadorFunciones* ManejadorFunciones::getInstancia(){
            if (ManejadorFunciones::instancia == NULL){
                ManejadorFunciones::instancia = new ManejadorFunciones();
            }
            return ManejadorFunciones::instancia;
        }

        /*  OPERACIONES BASICAS */
        bool ManejadorFunciones::add(Funcion* funcion){
            int t1 = this->funciones.size();
            this->funciones[funcion->getId()] = funcion;
            int t2 = this->funciones.size();
            return t1 == t2;
        }

        bool ManejadorFunciones::remove(string id){
            int t1 = this->funciones.size();
            this->funciones.erase(id);
            int t2 = this->funciones.size();
            return t1 == t2;
        }

        bool ManejadorFunciones::isMember(string id){
            return (this->funciones.find(id) != this->funciones.end());
        }

        Funcion* ManejadorFunciones::find(string id){
            return this->funciones[id];
        }

        bool ManejadorFunciones::isEmpty(){
            return this->funciones.empty();
        }


        /*  DESTRUCTOR */
        ManejadorFunciones::~ManejadorFunciones(){
            map<string,Funcion*>::iterator it;
            for (it = funciones.begin(); it != funciones.end(); ++it)
                delete it->second;
        }
