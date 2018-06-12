#ifndef MANEJADORPELICULAS_H
#define MANEJADORPELICULAS_H
#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
#include "../logica/Pelicula.h"

using namespace std;

class ManejadorPeliculas
{
    private:
        static ManejadorPeliculas* instancia;
        map<string, Pelicula*> peliculas;
        map<string,Pelicula*>::iterator it;
        ManejadorPeliculas();
    public:

        /*  OPERACIONES */
        static ManejadorPeliculas* getInstancia();

        /*  OPERACIONES BASICAS */
        bool add(Pelicula* cine);
        bool remove(string id);
        int size();
        bool isMember(string id);
        Pelicula* find(string id);
        bool isEmpty();
        void beginIterator();
        void next();
        Pelicula* getElement();
        Pelicula* operator[] (string x){
            return (this->peliculas[x]);
        };

        /*  DESTRUCTOR */
        virtual ~ManejadorPeliculas();
};

#endif // MANEJADORCINES_H
