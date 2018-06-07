#ifndef DTCREDITO_H
#define DTCREDITO_H
#include "DtTarjeta.h"
using namespace std;

class DtCredito: public DtTarjeta
{
    private:
         string financiera;
         float descuento;
    public:
        int getID();
        DtCredito(int idTarjeta, float montoTotal, string financiera, float descuento);
        ~DtCredito();

        string getFinanciera();
        float getDescuento();

        DtCredito();
        string toString();
};

#endif // DTCREDITO_H
