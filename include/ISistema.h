#ifndef ISISTEMA_H_INCLUDED
#define ISISTEMA_H_INCLUDED
#include <vector>
#include <map>
#include <string>
#include "datatypes/DtTest.h"
#include "logica/Reloj.h"
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
#include "manejadores/ManejadorCines.h"
#include "manejadores/ManejadorFunciones.h"
#include "manejadores/ManejadorPeliculas.h"
#include "manejadores/ManejadorUsuarios.h"
#include "manejadores/ListaDt.h"

using namespace std;

using namespace Util;

class ISistema {

    public:
        /* RELOJ */
        virtual float getDescuento(string financiera)=0;
        virtual DtFecha getFechaActual()=0;
        virtual void setFechaActual(int dia, int mes, int anio, int hora, int minuto)=0;

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

        /***********************************************************************************/
        /***********************************************************************************/
        /*****************************     N U E V O S     *********************************/
        /***********************************************************************************/
        /***********************************************************************************/

        /* LISTAR TODAS LAS PELICULAS */
        virtual ListaDt<string,DtPelicula> listarPeliculas()=0;
        /* LISTAR TODOS LOS CINES */
        virtual ListaDt<int,DtCine> listarCines()=0;
        /* LISTAR TODAS LAS FUNCIONES */
        virtual ListaDt<int,DtFuncion> listarFunciones()=0;
        /* LISTAR SALAS X CINE */
        virtual ListaDt<int,DtSala> listarSalas(int idCine)=0;
        /* LISTAR CINES X PELICULA */
        virtual ListaDt<int,DtCine> listarCines(string titulo)=0;
        /* LISTAR COMENTARIOS X PELICULA */
        virtual ListaDt<int,DtComentario> listarComentarios(string titulo)=0;
        /* LISTAR FUNCIONES X PELICULA Y CINE  POSTARIOR A FECHA Y HORA ACTUAL*/
        virtual ListaDt<int,DtFuncion> listarFunciones(int idCine, string titulo, DtFecha fecha)=0;
        /* LISTAR PUNTAJES X PELICULA */
        virtual ListaDt<string,DtPuntaje> listarPuntajes(string titulo)=0;
        /* LISTAR RESERVAS X USUARIO */
        virtual ListaDt<int,DtReserva> listarReservas(string nickName)=0;

        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/

        virtual DtTest test()=0;
};

#endif // ISISTEMA_H_INCLUDED
