#ifndef DEBITO_H
#define DEBITO_H
#include "Tarjeta.h"

class Debito : public Tarjeta
{
    private:
        string banco;
    public:
        void setBanco(string banco);
        string getBanco();
        bool isEqual(Tarjeta * t);
        string toString();

        Debito(float montoTotal, string banco);
        ~Debito();
};

#endif // DEBITO_H
