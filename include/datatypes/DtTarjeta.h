#ifndef DTTARJETA_H
#define DTTARJETA_H
#include <string>
using namespace std;

class DtTarjeta
{

    private:
        float montoTotal;

    public:
        DtTarjeta();
        DtTarjeta(float montoTotal);
       
        virtual float getMontoTotal();
        virtual string toString();
        
         virtual ~DtTarjeta();

};

#endif // DTTARJETA_H
