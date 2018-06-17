#ifndef DTRESERVA_H
#define DTRESERVA_H
#include "DtTarjeta.h"
#include "DtFuncion.h"
#include "DtCredito.h"
#include <string>

using namespace std;

class DtReserva
{
   private:
        int id;
        int cantAsientos;
        DtTarjeta tarjeta;
        DtFuncion funcion;

    public:
        DtReserva();
        DtReserva(int id, int cantAsientos, DtTarjeta tarjeta, DtFuncion funcion);

        int getID();
        int getCantAsientos();

        bool isEqual(DtReserva* reserva);
        string toString();

        virtual ~DtReserva();
};

#endif // DTRESERVA_H
