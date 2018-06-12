#include "../../include/manejadores/ManejadorPeliculas.h"

        ManejadorPeliculas* ManejadorPeliculas::instancia = NULL;

        ManejadorPeliculas::ManejadorPeliculas(){}


        /*  OPERACIONES */
        ManejadorPeliculas* ManejadorPeliculas::getInstancia(){
            if (ManejadorPeliculas::instancia == NULL){
                ManejadorPeliculas::instancia = new ManejadorPeliculas();
            }
            return ManejadorPeliculas::instancia;
        }

        /*  OPERACIONES BASICAS */
        bool ManejadorPeliculas::add(Pelicula* pelicula){
            cout << "Titulo: " + pelicula->getID() + " ";
            this->peliculas[pelicula->getID()] = pelicula;
            return true;
        }

        bool ManejadorPeliculas::remove(string id){
            int t1 = this->peliculas.size();
            this->peliculas.erase(id);
            int t2 = this->peliculas.size();
            return t1 == t2;
        }

        bool ManejadorPeliculas::isMember(string id){
            return (this->peliculas.find(id) != this->peliculas.end());
        }

        Pelicula* ManejadorPeliculas::find(string id){
            return this->peliculas[id];
        }

        bool ManejadorPeliculas::isEmpty(){
            return this->peliculas.empty();
        }

        int ManejadorPeliculas::size(){
            return this->peliculas.size();
        }

        void ManejadorPeliculas::beginIterator(){
            this->it = peliculas.begin();
        }


        Pelicula* ManejadorPeliculas::getElement(){
            if (it != peliculas.end()){
                return it->second;
            }
            else{
                return NULL;
            }
        }

        void ManejadorPeliculas::next(){
            this->it++;
        };

        /*  DESTRUCTOR */
        ManejadorPeliculas::~ManejadorPeliculas(){
            map<string,Pelicula*>::iterator it;
            for (it = peliculas.begin(); it != peliculas.end(); ++it)
                delete it->second;
        }
