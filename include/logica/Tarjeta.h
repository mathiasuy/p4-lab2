#ifndef TARJETA_H
#define TARJETA_H
#include "../datatypes/DtTarjeta.h"
#include <string>
#define DESCUENTO_FINANCIERA 6
using namespace std;

class Tarjeta
{
    private:
        static int idGlobal;

    public:
        void setMontoTotal(float montoTotal);
        virtual DtTarjeta getDt()=0;
        virtual string toString() = 0;
        virtual float getMontoTotal()=0;
        Tarjeta(float montoTotal);
        virtual ~Tarjeta();

    protected:
        float montoTotal;

};

#endif // TARJETA_H
