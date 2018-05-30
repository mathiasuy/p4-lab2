#include "../../include/manejadores/ManejadorCines.h"

        ManejadorCines* ManejadorCines::instancia = NULL;
        map<int, Cine*> cines;

        ManejadorCines::ManejadorCines(){}


        /*  OPERACIONES */
        ManejadorCines* ManejadorCines::getInstancia(){
            if (ManejadorCines::instancia == NULL){
                ManejadorCines::instancia = new ManejadorCines();
            }
            return ManejadorCines::instancia;
        }

        /*  OPERACIONES BASICAS */
        bool ManejadorCines::add(Cine* cine){
            int t1 = this->cines.size();
            this->cines[cine->getId()] = cine;
            int t2 = this->cines.size();
            return t1 == t2;
        }

        bool ManejadorCines::remove(string id){
            int t1 = this->cines.size();
            this->cines.erase(id);
            int t2 = this->cines.size();
            return t1 == t2;
        }

        bool ManejadorCines::isMember(string id){
            return (this->cines.find(id) != this->cines.end());
        }

        Cine* ManejadorCines::find(string id){
            return this->cines[id];
        }

        bool ManejadorCines::isEmpty(){
            return this->cines.empty();
        }


        /*  DESTRUCTOR */
        ManejadorCines::~ManejadorCines(){
            map<string,Cine*>::iterator it;
            for (it = cines.begin(); it != cines.end(); ++it)
                delete it->second;
        }
