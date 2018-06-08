#ifndef DTSALA_H
#define DTSALA_H


class DtSala
{
private:
    int idSala;
    int cantAsientos;

public:
    DtSala();
    DtSala(int idSala, int cantAsientos);
    
    int getID();
    int getCanAsientos;
    
    ~DtSala();
};

#endif // DTSALA_H
