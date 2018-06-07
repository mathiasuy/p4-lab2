#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <string>

using namespace std;

class DtPelicula
{
private:
    string titulo;
    string poster;
    float puntajePromedio;

    public:
        string getID();
        string getTitulo();
        string getPoster();
        DtPelicula();
        float getPuntajePromedio();
        DtPelicula(string titulo, string poster, float puntajePromedio);
        ~DtPelicula();
};

#endif // DTPELICULA_H
