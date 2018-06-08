#ifndef DTFUNCION_H
#define DTFUNCION_H
#include <string>

using namespace std;

class DtFuncion
{
    private:
        int id;
        int asientosReservados;
        float precioEntrada;
        
    public:
        DtFuncion();
        DtFuncion(int id, int asientosReservados, float precioEntrada);
        
        int getID();
        int getAsientosReservados();
        float getPrecio();
        
        string toString();
        bool isEqual(DtFuncion *funcion);

        virtual ~DtFuncion();
};

#endif // DTFUNCION_H
