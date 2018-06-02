#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include <map>
#include <Funcion.h>

using namespace std;

class Funcion;

class Sala
{
    private:
        int id;
        int idGlobal;
        int capacidad;
        map<int, Funcion*> funciones;

    public:
        int getID();
        int getCapacidad();
        void setCapacidad(int id);
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(Funcion* funcion);

        bool isEqual(Sala* sala);
        string toString();

        Sala(int capacidad);
        virtual ~Sala();
};

#endif // SALA_H
