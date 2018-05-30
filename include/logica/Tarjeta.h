#ifndef TARJETA_H
#define TARJETA_H

#include <string>
using namespace std;

class Tarjeta
{
    private:
        int id;
        float montoTotal;
        static int idGlobal;

    public:
        int getID();
        float getMontoTotal();
        void setMontoTotal(float montoTotal);
        virtual bool isEqual(Tarjeta* t) = 0;
        virtual string toString() = 0;
        Tarjeta(int id, float montoTotal);
        virtual ~Tarjeta();

    protected:

};

#endif // TARJETA_H
