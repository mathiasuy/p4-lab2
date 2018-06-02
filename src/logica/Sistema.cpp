#include "../../include/logica/Sistema.h"
#include "include/logica/Cine.h"
#include "include/manejadores/ManejadorCines.h"
#include "include/manejadores/ManejadorUsuarios.h"
ManejadorCines *cines = ManejadorCines::getInstancia();


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
        bool altaFuncion(DtPelicula pelicula, DtSala sala, DtCine cine, DtFecha fecha){
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
