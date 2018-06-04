#ifndef DTCINE_H
#define DTCINE_H
#include "DtSala.h"
#include <vector>
#include <string>

using namespace std;

class DtCine
{
    private:
        int id;
        string direccion;
        float precioEntrada;
    public:
        int getID();
        string getDireccion();

        bool isEqual(DtCine dtCine);
        string toString();

        DtCine(int id, string direccion);
        virtual ~DtCine();

};

#endif // DTCINE_H
