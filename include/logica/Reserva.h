#ifndef RESERVA_H
#define RESERVA_H
#include "../datatypes/DtFuncion.h"
#include "../datatypes/DtPelicula.h"
#include "Pago.h"

class Reserva
{
    private:
        int id;
        int cantAsientos;
        DtFuncion dtFuncion;
        DtPelicula dtPelicula;
        Pago* pago;

    public:
        int getID();
        int getCantAsientos();
        DtFuncion getDtFuncion();
        DtPelicula getDtPelicula();
        Pago* getPago();
        void setCantAsientos(int cantAsientos);
        void setDtFuncion(DtFuncion funcion);
        void setDtPelicula(DtPelicula pelicula);
        void setPago(Pago* pago);

        bool isEqual(Reserva * reserva);
        string toString();

        ~Reserva();
        Reserva(int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula);
        Reserva(int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, Pago* pago);
};

#endif // RESERVA_H
