#ifndef MANEJADORFUNCIONES_H
#define MANEJADORFUNCIONES_H

#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <iomanip>
#include "../logica/Funcion.h"

using namespace std;

class ManejadorFunciones{
    private:
        static ManejadorFunciones* instancia;
        map<string, Funcion*> funciones;
        ManejadorFunciones();
    public:

        /*  OPERACIONES */
        static ManejadorFunciones* getInstancia();

        /*  OPERACIONES BASICAS */
        bool add(Funcion* funcion);
        bool remove(string id);
        bool isMember(string id);
        Funcion* find(string id);
        bool isEmpty();

        /*  DESTRUCTOR */
        virtual ~ManejadorFunciones();
};


#endif // MANEJADORFUNCIONES_H
