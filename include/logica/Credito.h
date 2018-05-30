#ifndef CREDITO_H
#define CREDITO_H
#include "../datatypes/DtFinanciera.h"
#include "Tarjeta.h"

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

        Credito(int id, float montoTotal, string financiera, float descuento);

        bool isEqual(Tarjeta * t);
        string toString();
        ~Credito();
};

#endif // CREDITO_H
