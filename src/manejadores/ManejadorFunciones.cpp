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
            this->funciones[funcion->getID()] = funcion;
            int t2 = this->funciones.size();
            return t1 == t2;
        }

        bool ManejadorFunciones::remove(int id){
            int t1 = this->funciones.size();
            this->funciones.erase(id);
            int t2 = this->funciones.size();
            return t1 == t2;
        }

        bool ManejadorFunciones::isMember(int id){
            return (this->funciones.find(id) != this->funciones.end());
        }

        Funcion* ManejadorFunciones::find(int id){
            return this->funciones[id];
        }

        bool ManejadorFunciones::isEmpty(){
            return this->funciones.empty();
        }
        bool ManejadorFunciones::size(){
            return this->funciones.size();
        }

        void ManejadorFunciones::beginIterator(){
            this->it = funciones.begin();
        }


        Funcion* ManejadorFunciones::getElement(){
            if (it != funciones.end()){
                return it->second;
            }
            else{
                return NULL;
            }
        }

        void ManejadorFunciones::next(){
            this->it++;
        };

        /*  DESTRUCTOR */
        ManejadorFunciones::~ManejadorFunciones(){
            map<int,Funcion*>::iterator it;
            for (it = funciones.begin(); it != funciones.end(); ++it)
                delete it->second;
        }
