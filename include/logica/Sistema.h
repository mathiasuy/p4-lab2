#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"

class Sistema : public ISistema
{
    private:
        static Sistema* instancia;
        Sistema(){};
    public:
        bool altaCine(int id, string direccion, vector<DtSala> salas);

        /*  PELICULA */
        bool altaFuncion(DtPelicula pelicula, DtSala sala, DtCine cine, DtFecha fecha);
        bool getPuntajePelicula(string nickName, DtPelicula pelicula);
        bool puntuarPelicula(string nickName, DtPelicula pelicula);
        bool eliminarPelicula(string titulo);

        /* USUARIO */
        bool login(string nickName, string password);
        bool crearReserva(string nickName, int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, DtPago pago);


        ~Sistema(){};
        static Sistema* getInstance();

};

#endif // SISTEMA_H
