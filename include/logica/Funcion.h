#ifndef FUNCION_H
#define FUNCION_H
#include "../datatypes/DtFecha.h"
#include <string>
#include "Cine.h"
#include "Pelicula.h"
#include "../datatypes/DtFuncion.h"

using namespace std;

class Pelicula;
class Sala;

class Funcion
{
    private:
        int id;
        static int idGlobal;
        int asientosReservados;
        float precioEntrada;
        DtFecha fehca;

        Sala* sala;
        Pelicula* pelicula;

    public:
        Pelicula* getPelicula();
        Sala* getSala();
        DtFecha getFecha();
        float getPrecio();
        DtFuncion getDtFuncion();
        int getAsientosReservados();
        int getAsientosLibres();
        void agregarAsientosReservados(int aumento);

        void setSala(Sala* sala);
        void setPelicula(Pelicula* pelicula);
        void setFecha(DtFecha fecha);
        void setPrecio(float precioEntrada);
        int getID();
        string toString();
        bool isEqual(Funcion *funcion);

        ~Funcion();
        Funcion(float precioEntrada, DtFecha fecha, Sala* sala , Pelicula *pelicula);
};

#endif // FUNCION_H
