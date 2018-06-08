#ifndef DTFUNCION_H
#define DTFUNCION_H


class DtFuncion
{
    private:
        int id;
        int asientosReservados;
        float precioEntrada;
        
    public:
        DtFuncion();
        DtFuncion(int id, int asientosReservados, float precioEntrada);
        
        int getID();
        int getAsientosReservados();
        float getPrecio();
        
        string toString();
        bool isEqual(DtFuncion *funcion);

        ~Funcion();
};

#endif // DTFUNCION_H
