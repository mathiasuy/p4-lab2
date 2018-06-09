#ifndef RELOJ_H
#define RELOJ_H
#include <string>
#include "../datatypes/DtFecha.h"
#include "../Utils.h"
class Reloj {

private:
        int dia;
        int mes;
        int anio;
        int hora;
        int minuto;
        static Reloj* r;
        Reloj();
        Reloj(int dia, int mes, int anio, int hora, int minuto);

public:
        static Reloj* getInstancia();

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void setHora(int hora);
        void setMinuto(int minuto);

        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
        DtFecha getFechaActual();
        std::string toString();
        //Reloj(const Reloj& orig);
        ~Reloj();
};

#endif // RELOJ_H
