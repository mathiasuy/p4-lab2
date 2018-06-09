#ifndef TARJETA_H
#define TARJETA_H
#include <string>
#include "../datatypes/DtTarjeta.h"
#define DESCUENTO_FINANCIERA 6

using namespace std;

class Tarjeta
{
    private:
        static int idGlobal;

    public:
        void setMonto(float monto);
        virtual DtTarjeta getDt()=0;
        virtual string toString()=0;
        virtual float getMonto()=0;
        Tarjeta(float monto);
        virtual ~Tarjeta();

    protected:
        float monto;

};

#endif // TARJETA_H
