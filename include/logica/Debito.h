#ifndef DEBITO_H
#define DEBITO_H
#include "Tarjeta.h"
#include "../datatypes/DtDebito.h"
#include "../datatypes/DtTarjeta.h"
#include <string>

using namespace std;

class Debito : public Tarjeta
{
    private:
        string banco;
    public:
        void setBanco(string banco);
        string getBanco();
        string toString();
        DtTarjeta getDt();
        float getMontoTotal();

        Debito(float montoTotal, string banco);
        ~Debito();
};

#endif // DEBITO_H
