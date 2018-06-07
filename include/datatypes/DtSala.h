#ifndef DTSALA_H
#define DTSALA_H


class DtSala
{
private:
    int idSala;
    int cantAsientos;

public:
        int getID();
    DtSala();
        DtSala(int idSala, int cantAsientos);
        ~DtSala();
};

#endif // DTSALA_H
