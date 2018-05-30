#include "Comentario.h"
#include "Puntaje.h"
#include "Funcion.h"
#ifndef PELICULA_H
#define PELICULA_H
#include <vector>
#include <map>

class Pelicula
{
    private:
        vector<Funcion> funciones;
        map<string,Puntaje*> puntajes;
        map<string,Comentario*> comentarios;
        string titulo;
        string poster;
        string sinopsis;
        float puntajePromedio;

    public:

    /* GETTER Y SETTERS */
        void setPoster(string poster);
        void setSinopsis(string sinopsis);
        void setPuntajePromedio();

        string getPoster();
        string getSinopsis();
        float getPuntajePromedio();

        string getId();
        string getTitulo();
        string toString();
        bool isEqual(Pelicula* pelicula);

        /* CONSTRUS Y DESTRUS */
        Pelicula(string titulo);
        Pelicula(string titulo, string poster, string sinopsis, float puntajePromedio);
        virtual ~Pelicula();

};

#endif // PELICULA_H
