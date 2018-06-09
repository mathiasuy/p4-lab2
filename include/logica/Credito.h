#ifndef CREDITO_H
#define CREDITO_H
#include "Tarjeta.h"
#include "../datatypes/DtCredito.h"

class Credito : public Tarjeta
{
    private:
        string financiera;
        float descuento;
    public:
        void setFinanciera(string financiera);
        void setDescuento (float descuento);
        string getFinanciera();
        float getDescuento();
        float getMontoTotal();
        DtTarjeta getDt();
        Credito(float montoTotal, string financiera, float descuento);

        string toString();
        ~Credito();
};

#endif // CREDITO_H
