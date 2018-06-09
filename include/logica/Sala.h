#ifndef SALA_H
#define SALA_H    map<int,Reserva*>::iterator it = this->reservas.begin();
#include <string>
#include <vector>
#include <map>
#include "Funcion.h"
#include "Cine.h"
#include "../datatypes/DtCine.h"

using namespace std;

class Funcion;
class Cine;

class Sala
{
    private:
        int id;
        int idGlobal;
        int capacidad;
        Cine* cine;
        map<int, Funcion*> funciones;

    public:
        int getID();
        int getCapacidad();
        Cine* getCine();
        DtSala getDt();
        void setCapacidad(int id);
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(Funcion* funcion);
        bool tieneFuncion(int id);
        bool perteneceA(Cine* cine);

        bool isEqual(Sala* sala);
        string toString();

        Sala(int capacidad, Cine* cine);
        virtual ~Sala();
};

#endif // SALA_H
