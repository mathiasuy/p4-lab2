#ifndef PUNTAJE_H
#define PUNTAJE_H
#include "../datatypes/DtPuntaje.h"
#include <string>
using namespace std;

class Puntaje
{
    private:
        string nickName;
        float puntaje;
        Puntaje();

    public:
        void setPuntaje(float puntaje);
        float getPuntaje();

        string getID();
        string getNickName();
        string toString();
        DtPuntaje getDt();
        bool isEqual(Puntaje *puntaje);

        /* CONSTRUS Y DESTRUS */
        Puntaje(string nickName, float puntaje);
        virtual ~Puntaje();
};


#endif // PUNTAJE_H
