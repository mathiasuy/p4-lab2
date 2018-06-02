#ifndef MANEJADORCINES_H
#define MANEJADORCINES_H

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
#include "../logica/Cine.h"

class ManejadorCines
{
    private:
        static ManejadorCines* instancia;
        map<string, Cine*> cines;
        ManejadorCines();
    public:

        /*  OPERACIONES */
        static ManejadorCines* getInstancia();

        /*  OPERACIONES BASICAS */
        bool add(Cine* cine);
        bool remove(string id);
        bool isMember(string id);
        Pelicula* find(string id);
        bool isEmpty();

        /*  DESTRUCTOR */
        virtual ~ManejadorCines();
};

#endif // MANEJADORCINES_H
