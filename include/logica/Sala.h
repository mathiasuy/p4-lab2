#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include "../datatypes/Funcion.h"

using namespace std;

class Sala
{
    private:
        int id;
        int capacidad;
        vector<Funcion*> funciones;

    public:
        int getID();
        int getCapacidad();
        void setCapacidad(int id);
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(Funcion* funcion);
        vector<Funcion*> listarFunciones();

        bool isEqual(Sala* sala);
        string toString();

        Sala(int id, int capacidad);
        virtual ~Sala();
};

#endif // SALA_H
