#ifndef SISTEMA_H
#define SISTEMA_H
#include "ISistema.h"
#include "../manejadores/ManejadorCines.h"
#include "../manejadores/ManejadorFunciones.h"
#include "../manejadores/ManejadorPeliculas.h"
#include "../manejadores/ManejadorUsuarios.h"

class Sala;
class Funcion;
class Pelicula;

class Sistema : public ISistema
{
    private:
        static Sistema* instancia;
        Sistema(){};

        //manejadores
        ManejadorCines *cines = ManejadorCines::getInstancia();
        ManejadorFunciones *funciones = ManejadorFunciones::getInstancia();
        ManejadorUsuarios *usuarios = ManejadorUsuarios::getInstancia();
        ManejadorPeliculas *peliculas = ManejadorPeliculas::getInstancia();


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
