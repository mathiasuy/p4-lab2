#ifndef DTFECHA_H
#define DTFECHA_H
#include <ctime>
#include <string>
using namespace std;
class DtFecha
{
    private:
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;
    public:
        int getDia();
        int getMes();
        int getAno();
        int getHora();
        int getMinuto();
        string toString();
        DtFecha getFechaActual();
        DtFecha();
        DtFecha(int dia, int mes, int ano, int hora, int minuto);
        virtual ~DtFecha();
};

#endif // DTFECHA_H
