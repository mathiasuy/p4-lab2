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
        void setDireccion(string direccion);
        void setPrecioEntradas(float precioEntrada);
        vector<DtSala> salas;
    public:
        int getID();
        string getDireccion();
        float getPrecioEntrada();

        bool isEqual(DtCine dtCine);
        string toString();

        DtCine(int id, string direccion, float precioEntrada, vector<DtSala> salas);
        virtual ~DtCine();

};

#endif // DTCINE_H
