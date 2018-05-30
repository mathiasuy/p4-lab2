#ifndef CINE_H
#define CINE_H
#include <string>
#include <map>
#include "Sala.h"

using namespace std;

class Cine
{
    private:
        int id;
        string direccion;
        float precioEntrada;
        map<int,Sala*> salas;
        Cine();
        static int idGlobal;

    public:
        /* GETTERS Y SETTERS */
        string getDireccion();
        float getPrecioEntrada();
        void setDireccion(string direccion);
        void setPrecioEntrada(float precioEntrada);

        int getId();
        string toString();
        bool isEqual(Cine *cine);

        /* CONSTRUS Y DESTRUS */
        Cine(int id);
        Cine(int id, string direccion, float precioEntrada);
        virtual ~Cine();
};

#endif // CINE_H
