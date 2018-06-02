#ifndef SISTEMA_H
#define SISTEMA_H

#include "../../include/logica/Sistema.h"
#include <string>
#include <vector>


        Sistema* Sistema::instancia = NULL;


        Sistema* Sistema::getInstance(){

            if (Sistema::instancia == NULL){
                Sistema::instancia = new Sistema();
            }

            return Sistema::instancia;
        }

        bool altaCine(string direccion, vector<DtSala> capacidadSalas){
            Cine cineNuevo = new Cine(string, capacidadSalas);
            cines->add(cineNuevo);
            return true;
        };

        /*  PELICULA */
        bool altaFuncion(int asientos, float precioEntrada, DtFecha fecha, Sala* sala, Pelicula* pelicula){
            Funcion fnueva = new Funcion(asientos, precioEntrada, fecha, sala, pelicula);
            funciones->add(fnueva);
            return true;
        };

        bool Sistema::getPuntajePelicula(string nickName, DtPelicula pelicula){
            return (peliculas.isMember(pelicula.getTitulo()));
        };

        bool Sistema::puntuarPelicula(string nickName, DtPelicula pelicula){
            
             
            return (peliculas.isMember(pelicula.getTitulo()));
               
                }
         

        bool Sistema::eliminarPelicula(string titulo){
            return (peliculas.isMember(titulo));
        };

        /* USUARIO */
        bool Sistema::login(string nickName, string password){
            if(usuarios.isMember(nickName)){
             //si esta, lo busco
             Usuario* usuario = usuarios.find(nickName);
             return (usuario->getPassword() == password);
            
        }
            else return false;
        };

        bool crearReserva(string nickName, int id, int cantAsientos, DtFuncion funcion, DtPelicula pelicula, DtPago pago){
            return true;
        };


#endif // SISTEMA_H
