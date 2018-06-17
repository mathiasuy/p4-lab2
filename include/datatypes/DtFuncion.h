#ifndef DTFUNCION_H
#define DTFUNCION_H
#include <string>
#include "DtPelicula.h"
#include "DtSala.h"
#include "DtFecha.h"

using namespace std;

class DtFuncion
{
    private:
        int id;
        int asientosReservados;
        float precioEntrada;
        DtSala sala;
        DtPelicula pelicula;
        DtFecha fecha;

    public:
        DtFuncion();
        DtFuncion(int id, int asientosReservados, DtFecha f, float precioEntrada, DtSala sala, DtPelicula pelicula);

        int getID();
        int getAsientosReservados();
        float getPrecio();
        DtSala getSala();
        DtFecha getFecha();
        DtPelicula getPelicula();

        string toString();
        bool isEqual(DtFuncion *funcion);

        virtual ~DtFuncion();
};

#endif // DTFUNCION_H
