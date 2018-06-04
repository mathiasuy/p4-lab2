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
        map<int, Funcion*> funciones;
        map<int,Funcion*>::iterator it;        
        ManejadorFunciones();
    public:

        /*  OPERACIONES */
        static ManejadorFunciones* getInstancia();

        /*  OPERACIONES BASICAS */
        bool add(Funcion* funcion);
        bool remove(int id);
        bool isMember(int id);
        Funcion* find(int id);
        bool isEmpty();
        void beginIterator();
        void next();
        Funcion* getElement();        

        /*  DESTRUCTOR */
        virtual ~ManejadorFunciones();
};


#endif // MANEJADORFUNCIONES_H
