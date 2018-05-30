#ifndef PAGO_H
#define PAGO_H
#include "Tarjeta.h"

class Pago
{
    private:
        float monto;
        Tarjeta* tarjeta;
        int id;
    public:
        int getID();
        float getMonto();
        Tarjeta* getTarjeta();
        void setMonto(float monto);
        void setTarjeta (Tarjeta* tarjeta);

        bool isEqual(Pago* t);
        string toString();


        Pago(int id, float monto, Tarjeta* tarjeta);
        virtual ~Pago();
};

#endif // PAGO_H
