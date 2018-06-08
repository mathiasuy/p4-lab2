#ifndef DTSALA_H
#define DTSALA_H
#include <string>
#include "DtCine.h"

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
    
    virtual ~DtSala();
};

#endif // DTSALA_H
