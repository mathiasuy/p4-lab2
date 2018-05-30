#ifndef DTCREDITO_H
#define DTCREDITO_H
#include "../include/datatypes/DtTarjeta.h"
using namespace std;

class DtCredito: public DtTarjeta
{
    private:
         string banco;
         float descuento;


    public:
        DtCredito(string financiera, float descuento);
        DtCredito();
        string getFinanciera();
        virtual ~DtCredito();
        virtual float getMontoTotal();
        virtual bool isEqual(DtTarjeta* t) = 0;
        virtual string toString() = 0;
    protected:


};

#endif // DTCREDITO_H
