#ifndef CREDITO_H
#define CREDITO_H
#include "Tarjeta.h"
#include "../datatypes/DtCredito.h"

using namespace std;


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
        float getMonto();
        DtTarjeta getDt();
        Credito(float monto, string financiera, float descuento);

        string toString();
        ~Credito();
};

#endif // CREDITO_H
