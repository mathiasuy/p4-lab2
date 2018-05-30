#include "../../include/logica/Sistema.h"
        Sistema* Sistema::instancia = NULL;

        Sistema* Sistema::getInstance(){

            if (Sistema::instancia == NULL){
                Sistema::instancia = new Sistema();
            }

            return Sistema::instancia;
        }

        bool altaCine(int id, string direccion, vector<DtSala> salas){

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
            return true;
        };

        bool crearReserva(string nickName, int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, DtPago pago){
            return true;
        };
