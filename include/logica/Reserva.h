#ifndef RESERVA_H
#define RESERVA_H
#include "../datatypes/DtFuncion.h"
#include "../datatypes/DtPelicula.h"

#include "../logica/Tarjeta.h"

using namespace std;

class Reserva
{
    private:
        int id;
        int cantAsientos;
        Funcion* funcion;
        Tarjeta* tarjeta;
        int idGlobal;
        
    public:
        int getID();
        int getCantAsientos();
        Funcion* getFuncion();
        Tarjeta* getTarjeta();
        
        void setMontoTotal(float monto);
        void setFuncion(Funcion* funcion);
        void setTarjeta(Tarjeta* tarjeta);
        void setCantAsientos(int cantAsientos);
        
        bool isEqual(Reserva * reserva);
        string toString();

        ~Reserva();
        Reserva(int cantAsientos, DtFuncion funcion, DtPelicula pelicula);
        
        /**
         * Crear Reserva para pago con tarjeta de Credito
         */
        Reserva(int cantAsientos, Funcion* funcion, float montoTotal, float descuento);
        
        /**
         * Crear Reserva para pago con tarjeta de Debito
         */
        Reserva(int cantAsientos, Funcion* funcion, float montoTotal, string  banco);
};

#endif // RESERVA_H
