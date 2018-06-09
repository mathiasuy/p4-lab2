#ifndef DTSALA_H
#define DTSALA_H
#include <string>
#include "../../include/datatypes/DtCine.h"

using namespace std;

class DtSala
{
private:
    int idSala;
    int cantAsientos;
    DtCine cine;

public:
    DtSala();
    DtSala(int idSala, int cantAsientos, DtCine cine);

    int getID();
    int getCantAsientos();
    string toString();

    virtual ~DtSala();
};

#endif // DTSALA_H
