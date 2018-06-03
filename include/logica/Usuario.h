#ifndef USUARIO_H
#define USUARIO_H
#include <map>
#include <iomanip>
#include "Reserva.h"
#include <string>
using namespace std;

class Usuario
{
    private:
        string nickName;
        string imagen;
        string password;
        map<int,Reserva*> reservas;

    public:

        string getNickName();
        string getImagen();
        string getPassword();

        void setImagen(string imagen);
        void setPassword(string password);
        bool tieneReservaFuncion(int id);
        bool eliminarReservaConFuncion(int idFuncion);

        bool agregarReservaDebito(int cantAsientos, Funcion* funcion, float montoTotal, string  banco);
        bool agregarReservaCredito(int cantAsientos, Funcion* funcion, float montoTotal, float descuento);
        bool quitarReserva(int id);
        bool tieneReserva(int id);
        
        map<int,Reserva*> getReservas();
        Usuario(string nickName, string imagen, string password);
        ~Usuario();
};

#endif // USUARIO_H
