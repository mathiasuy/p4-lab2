#ifndef DTPELICULA_H
#define DTPELICULA_H
#include <string>


using namespace std;


class DtPelicula
{
private:
    string titulo;
    string poster;
    string sinopsis;
    float puntajePromedio;

    public:
        DtPelicula();
        DtPelicula(string titulo, string poster, float puntajePromedio);
        
        string getID();
        string getTitulo();
        string getSinopsis();
        string getPoster();
        float getPuntajePromedio();
        
        ~DtPelicula();
};

#endif // DTPELICULA_H
