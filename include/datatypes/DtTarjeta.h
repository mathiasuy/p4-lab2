#ifndef DTTARJETA_H
#define DTTARJETA_H
#include <string>
using namespace std;

class DtTarjeta
{

    private:
             int idTarjeta;
             float montoTotal;



    public:
        DtTarjeta();
        DtTarjeta(int idTarjeta, float montoTotal);
        virtual ~DtTarjeta();
        int getIdTarjeta();
        virtual float getMontoTotal(float precio);
        virtual bool isEqual(DtTarjeta* t) = 0;
        virtual string toString() = 0;

    //protected:

};

#endif // DTTARJETA_H
