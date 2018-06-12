#ifndef SISTEMA_H
#define SISTEMA_H
#include "../ISistema.h"

class Sala;
class Funcion;
class Pelicula;

using namespace Util;
using namespace std;

class Sistema : public ISistema
{
    private:
        static Sistema* instancia;
        Sistema();

        /*  LISTAS  */
        static ManejadorCines *cines;
        static ManejadorFunciones *funciones;
        static ManejadorUsuarios *usuarios;
        static ManejadorPeliculas *peliculas;


    public:

        /* RELOJ */
        DtFecha getFechaActual();
        void setFechaActual(int dia, int mes, int anio, int hora, int minuto);
        /*    CINE    */
        bool altaCine(string direccion, vector<int> capacidadSalas) ;

        /*  PELICULA */
        float getDescuento(string financiera);
        bool altaFuncion(float precioEntrada, DtFecha fecha, int idSala, int idCine, string tituloPelicula) ;
        float getPuntajePelicula(string nickName, string tituloPelicula) ;
        bool puntuarPelicula(string nickName, string tituloPelicula, float puntaje) ;
        bool comentarPelicula(string nickName, string tituloPelicula, string comentario, int esRespuestaDeID) ;
        bool comentarPelicula(string nickName, string tituloPelicula, string comentario) ;
        bool eliminarPelicula(string titulo) ;

        /*  USUARIO  */
        bool login(string nickName, string password) ;
        bool crearReserva(string nickName,int cantAsientos, int idFuncion, string financiera, float descuento, float montoTotal) ;
        bool crearReserva(string nickName, int cantAsientos, int idFuncion, string banco, float montoTotal) ;

        /***********************************************************************************/
        /***********************************************************************************/
        /*****************************     N U E V O S     *********************************/
        /***********************************************************************************/
        /***********************************************************************************/

        /* LISTAR TODAS LAS PELICULAS */
        ListaDt<string,DtPelicula> listarPeliculas();
        /* LISTAR TODOS LOS CINES */
        ListaDt<int,DtCine> listarCines();
        /* LISTAR SALAS X CINE */
        ListaDt<int,DtSala> listarSalas(int idCine);
        /* LISTAR CINES X PELICULA */
        ListaDt<int,DtCine> listarCines(string titulo);
        /* LISTAR COMENTARIOS X PELICULA */
        ListaDt<int,DtComentario> listarComentarios(string titulo);
        /* LISTAR FUNCIONES X PELICULA Y CINE  POSTARIOR A FECHA Y HORA ACTUAL*/
        ListaDt<int,DtFuncion> listarFunciones(int idCine, string titulo, DtFecha fecha);
        /* LISTAR PUNTAJES X PELICULA */
        ListaDt<string,DtPuntaje> listarPuntajes(string titulo);
        /* LISTAR RESERVAS X USUARIO */
        ListaDt<int,DtReserva> listarReservas(string nickName);

        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/
        /***********************************************************************/

        /*  SISTEMA  */
        DtTest test();
        static Sistema* getInstance();
        ~Sistema(){};
};

#endif // SISTEMA_H
