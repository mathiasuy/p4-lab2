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
