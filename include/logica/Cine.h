#ifndef CINE_H
#define CINE_H
#include <string>
#include <map>
#include <vector>
#include "Sala.h"
#include "../Utils.h"

using namespace std;

class Sala;

class Cine
{
    private:
        int id;
        string direccion;
        map<int,Sala*> salas;
        Cine();
        static int idGlobal;

    public:
        /* GETTERS Y SETTERS */
        string getDireccion();

        void setDireccion(string direccion);
        int getID();
        string toString();
        bool isEqual(Cine *cine);
        bool tieneSala(int id);
        Sala* getSala(int id);

        /* CONSTRUS Y DESTRUS */
        Cine(string direccion, vector<int> salas);
        virtual ~Cine();
};

#endif // CINE_H
