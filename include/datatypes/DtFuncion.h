#ifndef DTFUNCION_H
#define DTFUNCION_H
#include <string>
#include "DtPelicula.h"
#include "DtSala.h"

using namespace std;

class DtFuncion
{
    private:
        int id;
        int asientosReservados;
        float precioEntrada;
        DtSala sala;
        DtPelicula pelicula;
        
    public:
        DtFuncion();
        DtFuncion(int id, int asientosReservados, float precioEntrada, DtSala sala, DtPelicula pelicula);
        
        int getID();
        int getAsientosReservados();
        float getPrecio();
        
        string toString();
        bool isEqual(DtFuncion *funcion);

        virtual ~DtFuncion();
};

#endif // DTFUNCION_H
