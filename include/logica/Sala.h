#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include <map>
#include "Funcion.h"
#include "Cine.h"

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
        void setCapacidad(int id);
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(Funcion* funcion);
        bool tieneFuncion(int id);

        bool isEqual(Sala* sala);
        string toString();

        Sala(int capacidad, Cine* cine);
        virtual ~Sala();
};

#endif // SALA_H
