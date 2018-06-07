#ifndef USUARIO_H
#define USUARIO_H
#include <map>
#include <iomanip>
#include "Reserva.h"
#include "../manejadores/ListaDt.h"
#include <string>

using namespace Util;
using namespace std;

class Usuario
{
    private:
        string nickName;
        string imagen;
        string password;
        map<int,Reserva*> reservas;

    public:
        string getID();
        string getNickName();
        string getImagen();
        string getPassword();

        void setImagen(string imagen);
        void setPassword(string password);
        bool tieneReservaFuncion(int id);
        void eliminarReservaConFuncion(int idFuncion);

        bool agregarReservaDebito(int cantAsientos, Funcion* funcion, string  banco, float montoTotal);
        bool agregarReservaCredito(int cantAsientos, Funcion* funcion, string financiera, float descuento, float montoTotal);
        bool quitarReserva(int id);
        bool tieneReserva(int id);

        ListaDt<int,DtReserva> listarDtReservas();
        
        map<int,Reserva*> getReservas();
        Usuario(string nickName, string imagen, string password);
        ~Usuario();
};

#endif // USUARIO_H
