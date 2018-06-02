#include "../../include/logica/Sistema.h"
#include "include/logica/Cine.h"
#include "include/manejadores/ManejadorCines.h"
#include "include/manejadores/ManejadorUsuarios.h"
#include "include/manejadores/ManejadorFunciones.h"
#include "include/manejadores/ManejadorPeliculas.h"

ManejadorCines *cines = ManejadorCines::getInstancia();
ManejadorCines *funciones = Manejadorfunciones::getInstancia();
ManejadorCines *usuarios = ManejadorUsuarios::getInstancia();
ManejadorCines *peliculas = ManejadorPeliculas::getInstancia();


        Sistema* Sistema::instancia = NULL;

        Sistema* Sistema::getInstance(){

            if (Sistema::instancia == NULL){
                Sistema::instancia = new Sistema();
            }

            return Sistema::instancia;
        }

        bool altaCine(int id, string direccion, vector<DtSala> salas){
            Cine cineNuevo = new Cine(string, salas);
            cines->add(cineNuevo);
            return true;
        };

        /*  PELICULA */
        bool altaFuncion(int asientos, float precioEntrada, DtFecha fecha, Sala* sala, Pelicula* pelicula){
            Funcion fnueva = new Funcion(asientos, precioEntrada, fecha, sala, pelicula);
            funciones->add(fnueva);
            return true;
        };

        bool getPuntajePelicula(string nickName, DtPelicula pelicula){
            return true;
        };

        bool puntuarPelicula(string nickName, DtPelicula pelicula){
            return true;
        };

        bool eliminarPelicula(string titulo){
            return true;
        };

        /* USUARIO */
        bool login(string nickName, string password){
            if(peliculas.isMember(nickName)){
             //si esta, lo busco
             Usuario* usuario = peliculas.find(nickName);
             return (usuario.getPassword() == password);
            
        }
            else return false;
        };

        bool crearReserva(string nickName, int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, DtPago pago){
            return true;
        };
