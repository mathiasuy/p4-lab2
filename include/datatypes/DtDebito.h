#ifndef DTDEBITO_H
#define DTDEBITO_H

#include <string>
#include "../datatypes/DtTarjeta.h"

using namespace std;

class DtDebito : public DtTarjeta
{
    private:
         string banco;

    public:
        DtDebito(float monto, string banco);
        DtDebito();

        string getBanco();
        string toString();

        virtual ~DtDebito();
};

#endif // DTDEBITO_H
