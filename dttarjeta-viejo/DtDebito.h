#ifndef DTDEBITO_H
#define DTDEBITO_H
#include "../include/datatypes/DtTarjeta.h"
using namespace std;

class DtDebito
{
    private:
         string banco;



    public:
        DtDebito(string banco);
        DtDebito();
        string getBanco();
        virtual ~DtDebito();
        virtual float getMontoTotal(float precio);
        virtual bool isEqual(DtTarjeta* t) = 0;
        virtual string toString() = 0;

    protected:


};

#endif // DTDEBITO_H
