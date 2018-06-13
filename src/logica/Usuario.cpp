#include "../../include/logica/Usuario.h"
#include "iostream"
Usuario::~Usuario()
{
    //dtor
}


string Usuario::getNickName(){
    return this->nickName;
};

string Usuario::getID(){
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

bool Usuario::agregarReservaDebito(int cantAsientos, Funcion* funcion, string  banco, float montoTotal){
    Reserva* reserva = new Reserva(cantAsientos,funcion,banco,montoTotal);
    this->reservas[reserva->getID()] = reserva;
//    cout << this->getImagen()   << endl;
//    cout << reservas.size()     << endl;
//    cout << this->getImagen()   << endl;
    return true;
};

void Usuario::eliminarReservaConFuncion(int idFuncion){
    map<int,Reserva*>::iterator it = reservas.begin();
    bool encontre = false;
    while (it != this->reservas.end() && !encontre){
        if (it->second->tieneFuncion(idFuncion)){
            encontre = true;
            delete it->second;
        }else{
            it++;
        }
    }
};

bool Usuario::agregarReservaCredito(int cantAsientos, Funcion* funcion,string financiera, float descuento, float montoTotal){
    Reserva* reserva = new Reserva(cantAsientos,funcion,financiera,descuento,montoTotal);
    this->reservas[reserva->getID()] = reserva;
    return true;
};

bool Usuario::quitarReserva(int id){
    return this->reservas.erase(id);
};

bool Usuario::tieneReserva(int id){
    return (this->reservas.find(id) != this->reservas.end());
};

bool Usuario::tieneReservaFuncion(int id){
    map<int,Reserva*>::iterator it = this->reservas.begin();
    while (it != this->reservas.end()){
        if (it->second->getFuncion()->getID() == id){
            return true;
        }
        it++;
    }
    return false;
};

ListaDt<int,DtReserva> Usuario::listarDtReservas(){
    ListaDt<int,DtReserva> dt;
    map<int, Reserva*>::iterator it = reservas.begin();
    while (it != reservas.end()){
        dt.add(it->second->getDt());
        it++;
    }
    return dt;
};



