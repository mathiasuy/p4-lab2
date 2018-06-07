#ifndef SISTEMA_H
#define SISTEMA_H
#include "../ISistema.h"

class Sala;
class Funcion;
class Pelicula;

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
        /*    CINE    */
        bool altaCine(string direccion, vector<int> capacidadSalas) ;

        /*  PELICULA */
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
        map<string,DtPelicula> listarPeliculas();
        /* LISTAR TODOS LOS CINES */
        map<int,DtCine> listarCines();
        /* LISTAR SALAS X CINE */
        map<int,DtSala> listarSalas(int idCine);
        /* LISTAR CINES X PELICULA */
        map<int,DtCine> listarCines(string titulo);
        /* LISTAR COMENTARIOS X PELICULA */
        map<int,DtComentario> listarComentarios(string titulo);
        /* LISTAR FUNCIONES X PELICULA Y CINE  POSTARIOR A FECHA Y HORA ACTUAL*/
        map<int,DtFuncion> listarFunciones(int idCine, string titulo, DtFecha fecha);
        /* LISTAR PUNTAJES X PELICULA */
        map<string,DtPuntaje> listarPuntajes(string titulo);
        /* LISTAR RESERVAS X USUARIO */
        map<int,DtReserva> listarReservas(string nickName);

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
