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
        map<int, Funcion*> funciones;
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
        
         void agregarComentario(string nickname, string comentario);
        void agregarComentario(string nickname, string comentario, int esRespuestaDeID);
        void modificarComentario(int id, string comentario);
        

        string getPoster();
        string getSinopsis();
        float getPuntajePromedio();
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(int id);
        bool tieneFuncion(int id);
        Funcion* getFuncion(int id);
        map<int,Funcion*> listarFunciones();
        
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
