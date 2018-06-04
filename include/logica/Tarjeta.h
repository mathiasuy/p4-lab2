#ifndef TARJETA_H
#define TARJETA_H

#include <string>
using namespace std;

class Tarjeta
{
    private:
        float montoTotal;
        static int idGlobal;

    public:
        float getMontoTotal();
        void setMontoTotal(float montoTotal);
        virtual string toString() = 0;
        Tarjeta(float montoTotal);
        virtual ~Tarjeta();

    protected:

};

#endif // TARJETA_H
