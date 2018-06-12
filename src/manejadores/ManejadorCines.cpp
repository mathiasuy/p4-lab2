#include "../../include/manejadores/ManejadorCines.h"

        ManejadorCines* ManejadorCines::instancia = NULL;

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
//            int t1 = this->cines.size();
            this->cines[cine->getID()] = cine;
//            int t2 = this->cines.size();
//            return t1 == t2;
            return true;
        }

        bool ManejadorCines::remove(int id){
            int t1 = this->cines.size();
            this->cines.erase(id);
            int t2 = this->cines.size();
            return t1 == t2;
        }

        bool ManejadorCines::isMember(int id){
            return (this->cines.find(id) != this->cines.end());
        }

        Cine* ManejadorCines::find(int id){
            return this->cines[id];
        }

        bool ManejadorCines::isEmpty(){
            return this->cines.empty();
        }

        int ManejadorCines::size(){
            return this->cines.size();
        }


        /*  DESTRUCTOR */
        ManejadorCines::~ManejadorCines(){
            map<int,Cine*>::iterator it;
            for (it = cines.begin(); it != cines.end(); ++it)
                delete it->second;
        }



        void ManejadorCines::beginIterator(){
            this->it = cines.begin();
        }


        Cine* ManejadorCines::getElement(){
            if (it != cines.end()){
                return it->second;
            }
            else{
                return NULL;
            }
        }


        Cine* ManejadorCines::getElement(int i){
            return this->cines[i];
        }

        void ManejadorCines::next(){
            this->it++;
        };
