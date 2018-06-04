#ifndef DEBITO_H
#define DEBITO_H
#include "Tarjeta.h"
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

        Debito(float montoTotal, string banco);
        ~Debito();
};

#endif // DEBITO_H
