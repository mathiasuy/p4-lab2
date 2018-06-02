#include "../../include/logica/Usuario.h"

Usuario::~Usuario()
{
    //dtor
}


string Usuario::getNickName(){
    return this->nickName;
};

string Usuario::getImagen(){
    return this->imagen;
};

string Usuario::getPassword(){
    return this->password;
};

void Usuario::setImagen(string imagen){
    this->imagen = imagen;
};

void Usuario::setPassword(string password){
    this->password = password;
};

map<int,Reserva*> Usuario::getReservas(){
    return this->reservas;
};

Usuario::Usuario(string nickName, string imagen, string password){
    this->nickName = nickName;
    this->setImagen(imagen);
    this->setPassword(password);
};

bool Usuario::agregarReservaDebito(int cantAsientos, Funcion* funcion, float montoTotal, string  banco){
    Reserva reserva = new Reserva(cantAsientos,funcion,montoTotal,banco);
    this->reservas[reserva->getID()] = reserva;
};

bool Usuario::agregarReservaCredito(int cantAsientos, Funcion* funcion, float montoTotal, float descuento){
    Reserva reserva = new Reserva(cantAsientos,funcion,montoTotal,descuento);
    this->reservas[reserva->getID()] = reserva;
};

bool Usuario::quitarReserva(int id){
    this->reservas.erase(id);
};

bool Usuario::tieneReserva(int id){
    return (this->reservas.find(id) != this->reservas.end());
};