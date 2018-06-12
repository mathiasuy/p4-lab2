#ifndef SALA_H
#define SALA_H
#include <map>
#include "Funcion.h"
#include "../datatypes/DtSala.h"

class Cine;

class Sala
{
    private:
        int id;
        int capacidad;
        Cine* cine;
        map<int, Funcion*> funciones;

    public:
        int getID();
        void setID(int id);
        int getCapacidad();
        bool esDeCine(int idCine);
        DtSala getDt();
        Cine* getCine();
        void setCapacidad(int id);
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(Funcion* funcion);
        bool tieneFuncion(int id);
        bool perteneceA(Cine* cine);

        bool isEqual(Sala* sala);
        string toString();

        Sala(int id, int capacidad, Cine* cine);
        virtual ~Sala();
};

#endif // SALA_H
