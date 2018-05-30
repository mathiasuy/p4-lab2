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
        ManejadorPeliculas();
    public:

        /*  OPERACIONES */
        static ManejadorPeliculas* getInstancia();

        /*  OPERACIONES BASICAS */
        bool add(Pelicula* cine);
        bool remove(string id);
        bool isMember(string id);
        Pelicula* find(string id);
        bool isEmpty();

        /*  DESTRUCTOR */
        virtual ~ManejadorPeliculas();
};

#endif // MANEJADORCINES_H
