#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"
#include "include/manejadores/ManejadorCines.h"
#include "include/manejadores/ManejadorUsuarios.h"
#include "include/manejadores/ManejadorFunciones.h"
#include "include/manejadores/ManejadorPeliculas.h"

class Sistema : public ISistema
{
    private:
        static Sistema* instancia;
        Sistema(){};
    public:
        bool altaCine(string direccion, vector<DtSala> capacidadSalas);

        /*  PELICULA */
        bool altaFuncion(int asientos, float precioEntrada, DtFecha fecha, Sala* sala, Pelicula* pelicula);
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
