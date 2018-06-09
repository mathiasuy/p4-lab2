#ifndef SALA_H
#define SALA_H
#include <string>
#include <vector>
#include <map>
#include "../datatypes/DtSala.h"
#include "../datatypes/DtCine.h"

using namespace std;


class Cine;
class Funcion;

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

        Sala(int capacidad, Cine* cine);
        virtual ~Sala();
};

#endif // SALA_H
