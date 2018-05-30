#ifndef SALA_H
#define SALA_H
#include <string>
using namespace std;

class Sala
{
    private:
        int id;
        int capacidad;

    public:
        int getID();
        int getCapacidad();
        void setCapacidad(int id);

        bool isEqual(Sala* sala);
        string toString();

        Sala(int id, int capacidad);
        virtual ~Sala();
};

#endif // SALA_H
