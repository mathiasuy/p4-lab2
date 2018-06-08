#ifndef DTSALA_H
#define DTSALA_H
#include <string>

using namespace std;

class DtSala
{
private:
    int idSala;
    int cantAsientos;

public:
    DtSala();
    DtSala(int idSala, int cantAsientos);
    
    int getID();
    int getCantAsientos();
    
    virtual ~DtSala();
};

#endif // DTSALA_H
