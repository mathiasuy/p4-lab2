#ifndef FUNCION_H
#define FUNCION_H
#include "../datatypes/DtFecha.h"
#include <string>
#include "Sala.h"
#include "Cine.h"
#include "Pelicula.h"
using namespace std;

class Funcion
{
    private:
        int id;
        static int idGlobal;
        int asientosReservados;
        DtFecha fehca;

        Sala* sala;
        Pelicula* pelicula;

    public:
        Pelicula* getPelicula();
        Sala* getSala();
        DtFecha getFecha();

        void setSala(Sala* sala);
        void setCine(Cine* cine);
        void setFecha(DtFecha fecha);

        int getId();
        string toString();
        bool isEqual(Funcion *funcion);

        Funcion(int id);
        ~Funcion();
        Funcion(int id, Sala* sala , Cine *cine , DtFecha);
};

#endif // FUNCION_H
