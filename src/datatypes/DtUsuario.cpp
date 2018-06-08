#include "../../include/datatypes/DtUsuario.h"

DtUsuario::DtUsuario(){
    nickName = "";
    imagen = "";
    password = "";//ctor
}

DtUsuario::DtUsuario(string nickName, string imagen, string password){
    this->nickName = nickName;
    this->imagen = imagen;
    this->password = password;
};

string DtUsuario::getID(){
    return this->nickName;
};

string DtUsuario::getNickName(){
    return this->nickName;
};
string DtUsuario::getImagen(){
    return this->imagen;
};

string DtUsuario::getPassword(){
    return this->password;
};


 string DtUsuario::toString(){
     return "Datos del usuario " + this->getID();
 };

DtUsuario::~DtUsuario()
{
    //dtor
}
