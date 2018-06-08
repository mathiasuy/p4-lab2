#ifndef DTCREDITO_H
#define DTCREDITO_H

#include <string>
#include "DtTarjeta.h"

using namespace std;

class DtCredito: public DtTarjeta
{
    private:
         string financiera;
         float descuento;
    public:
        DtCredito(float montoTotal, string financiera, float descuento);
        DtCredito();

        string getFinanciera();
        float getDescuento();
        string toString();
  
        virtual ~DtCredito();
};

#endif // DTCREDITO_H
