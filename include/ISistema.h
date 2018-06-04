#ifndef ISISTEMA_H_INCLUDED
#define ISISTEMA_H_INCLUDED
#include <vector>
#include <map>
#include <string>
#include "datatypes/DtTest.h"
#include "datatypes/DtCine.h"
#include "datatypes/DtComentario.h"
#include "datatypes/DtCredito.h"
#include "datatypes/DtDebito.h"
#include "datatypes/DtFecha.h"
#include "datatypes/DtFuncion.h"
#include "datatypes/DtPelicula.h"
#include "datatypes/DtPuntaje.h"
#include "datatypes/DtReserva.h"
#include "datatypes/DtSala.h"
#include "datatypes/DtUsuario.h"
#include "manejadores/ManejadorCines.h"
#include "manejadores/ManejadorFunciones.h"
#include "manejadores/ManejadorPeliculas.h"
#include "manejadores/ManejadorUsuarios.h"

using namespace std;

class ISistema {

    public:
        virtual bool altaCine(string direccion, vector<int> capacidadSalas)=0;

        /*  PELICULA */
        virtual bool altaFuncion(float precioEntrada, DtFecha fecha, int idSala, int idCine, string tituloPelicula)=0;
        virtual float getPuntajePelicula(string nickName, string tituloPelicula)=0;
        virtual bool puntuarPelicula(string nickName, string tituloPelicula, float puntaje)=0;
        virtual bool comentarPelicula(string nickName, string tituloPelicula, string comentario, int esRespuestaDeID)=0;
        virtual bool comentarPelicula(string nickName, string tituloPelicula, string comentario)=0;
        virtual bool eliminarPelicula(string titulo)=0;

            /* USUARIO */
        virtual bool login(string nickName, string password)=0;
        virtual bool crearReserva(string nickName,int cantAsientos, int idFuncion, string financiera, float descuento, float montoTotal)=0;
        virtual bool crearReserva(string nickName, int cantAsientos, int idFuncion, string banco, float montoTotal)=0;
        virtual DtTest test()=0;
};

#endif // ISISTEMA_H_INCLUDED
