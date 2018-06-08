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
        void setMontoTotal(float montoTotal);
        virtual DtTarjeta getDt()=0;
        virtual string toString() = 0;
        virtual float getMontoTotal()=0;        
        Tarjeta(float montoTotal);
        virtual ~Tarjeta();

    protected:

};

#endif // TARJETA_H
