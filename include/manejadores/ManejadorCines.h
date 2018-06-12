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
        map<int, Cine*> cines;
        map<int,Cine*>::iterator it;
        ManejadorCines();
    public:

        /*  OPERACIONES */
        static ManejadorCines* getInstancia();



        /*  OPERACIONES BASICAS */
        bool add(Cine* cine);
        bool remove(int id);
        int size();
        bool isMember(int id);
        Cine* find(int id);
        bool isEmpty();
        void beginIterator();
        void next();
        Cine* getElement();
        Cine* getElement(int i);
        Cine* operator[] (int x){
            return (this->cines[x]);
        };

        /*  DESTRUCTOR */
        virtual ~ManejadorCines();
};

#endif // MANEJADORCINES_H
