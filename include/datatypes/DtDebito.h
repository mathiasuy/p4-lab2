#ifndef DTDEBITO_H
#define DTDEBITO_H

#include <string>
#include "../datatypes/DtTarjeta.h"
using namespace std;

class DtDebito : public DtTarjeta
{
    private:
         string banco;

    public:
        DtDebito(int idTarjeta, float monto, string banco);
        DtDebito();
        
        string getBanco();
        bool isEqual(DtDebito* t);
        string toString();
        
        virtual ~DtDebito();
};

#endif // DTDEBITO_H
