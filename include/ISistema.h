#ifndef ISISTEMA_H_INCLUDED
#define ISISTEMA_H_INCLUDED
#include <vector>
#include "DtSala.h"
#include "DtPelicula.h"
#include "DtPago.h"
#include "DtFuncion.h"
#include "DtFecha.h"
#include "DtCine.h"
#include <string>
using namespace std;

class ISistema {

    public:
    /*  CINE */
    /* 1 */ virtual bool altaCine(int id, string direccion, vector<DtSala> salas)=0;

    /*  PELICULA */
    /* 1 */ virtual bool altaFuncion(DtPelicula pelicula, DtSala sala, DtCine cine, DtFecha fecha) = 0;
    /* 1 */ virtual bool getPuntajePelicula(string nickName, DtPelicula pelicula) = 0;
    /* 1 */ virtual bool puntuarPelicula(string nickName, DtPelicula pelicula) = 0;
    /* 1 */ virtual bool eliminarPelicula(string titulo) = 0;

    /* USUARIO */
    /* 1 */ virtual bool login(string nickName, string password) = 0;
    /* 1 */ virtual bool crearReserva(string nickName, int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, DtPago pago) = 0;

};

#endif // ISISTEMA_H_INCLUDED
