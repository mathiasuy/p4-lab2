#ifndef ISISTEMA_H_INCLUDED
#define ISISTEMA_H_INCLUDED
#include <vector>
#include <string>
#include "datatypes/DtCine.h"
#include "datatypes/DtPelicula.h"
#include "datatypes/DtFuncion.h"
#include "datatypes/DtUsuario.h"
#include "datatypes/DtFecha.h"



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
    /* 1 */ virtual bool crearReserva(string nickName, int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula) = 0;

};

#endif // ISISTEMA_H_INCLUDED
