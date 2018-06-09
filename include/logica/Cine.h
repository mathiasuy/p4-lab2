#ifndef CINE_H
#define CINE_H
#include <string>
#include <map>
#include <vector>
#include "Sala.h"
#include "../datatypes/DtCine.h"
#include "../datatypes/DtSala.h"
#include "../manejadores/ListaDt.h"
#include "../Utils.h"

using namespace std;
using namespace Util;

class Sala;

class Cine
{
    private:
        int id;
        string direccion;
        map<int,Sala*> salas;
        static int idGlobal;

    public:
        /* GETTERS Y SETTERS */
        string getDireccion();
        DtCine getDt();
        void setDireccion(string direccion);
        int getID();
        string toString();
        bool isEqual(Cine *cine);
        bool tieneSala(int id);
        Sala* getSala(int id);
        ListaDt<int,DtSala> listarDtSalas();

        /* CONSTRUS Y DESTRUS */
        Cine(string direccion, vector<int> salas);
        virtual ~Cine();
};

#endif // CINE_H
