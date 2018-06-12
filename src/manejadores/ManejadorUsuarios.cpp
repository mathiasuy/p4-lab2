#include "../../include/manejadores/ManejadorUsuarios.h"

        ManejadorUsuarios* ManejadorUsuarios::instancia = NULL;
        map<int, Usuario*> usuarios;

        ManejadorUsuarios::ManejadorUsuarios(){}


        /*  OPERACIONES */
        ManejadorUsuarios* ManejadorUsuarios::getInstancia(){
            if (ManejadorUsuarios::instancia == NULL){
                ManejadorUsuarios::instancia = new ManejadorUsuarios();
            }
            return ManejadorUsuarios::instancia;
        }

        /*  OPERACIONES BASICAS */
        bool ManejadorUsuarios::add(Usuario* usuario){
            int t1 = this->usuarios.size();
            this->usuarios[usuario->getID()] = usuario;
            int t2 = this->usuarios.size();
            return t1 == t2;
        }

        bool ManejadorUsuarios::remove(string id){
            int t1 = this->usuarios.size();
            this->usuarios.erase(id);
            int t2 = this->usuarios.size();
            return t1 == t2;
        }

        int ManejadorUsuarios::size(){
            return this->usuarios.size();
        }

        bool ManejadorUsuarios::isMember(string id){
            return (this->usuarios.find(id) != this->usuarios.end());
        }

        Usuario* ManejadorUsuarios::find(string id){
            return this->usuarios[id];
        }

        bool ManejadorUsuarios::isEmpty(){
            return this->usuarios.empty();
        }


        void ManejadorUsuarios::beginIterator(){
            this->it = usuarios.begin();
        }


        Usuario* ManejadorUsuarios::getElement(){
            if (this->it != this->usuarios.end()){
                return it->second;
            }
            else{
                return NULL;
            }
        }

        void ManejadorUsuarios::next(){
            this->it++;
        };

        /*  DESTRUCTOR */
        ManejadorUsuarios::~ManejadorUsuarios(){
            map<string,Usuario*>::iterator it;
            for (it = usuarios.begin(); it != usuarios.end(); ++it)
                delete it->second;
        }
