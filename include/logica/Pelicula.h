#ifndef PELICULA_H
#define PELICULA_H
#include <map>
#include "Funcion.h"
#include "Comentario.h"
#include "Puntaje.h"
#include "../manejadores/ListaDt.h"
#include "../datatypes/DtPelicula.h"

using namespace std;

class Pelicula
{
    private:
        map<int, Funcion*> funciones;
        map<string,Puntaje*> puntajes;
        map<int,Comentario*> comentarios;
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
        void agregarPuntaje(string nickName, float puntaje);
        float getPuntaje(string nickName);
        void setPuntaje(string nickName, float puntaje);
        DtPelicula getDtPuntaje(string nickName);

        Util::ListaDt<int,DtComentario> listarDtComentarios();


        DtPelicula getDt();

        Util::ListaDt<string,DtPuntaje> listarDtPuntajes();

        string getPoster();
        string getSinopsis();
        float getPuntajePromedio();
        bool agregarFuncion(Funcion* funcion);
        bool quitarFuncion(int id);
        bool tieneFuncion(int id);
        Funcion* getFuncion(int id);
        map<int,Funcion*> listarFunciones();

        string getID();
        string getTitulo();
        string toString();
        bool isEqual(Pelicula* pelicula);

        /* CONSTRUS Y DESTRUS */
        Pelicula(string titulo, string poster, string sinopsis);
        virtual ~Pelicula();

};

#endif // PELICULA_H
