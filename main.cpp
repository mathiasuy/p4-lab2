#include "include/ISistema.h"
#include "include/Factory.h"

ISistema* interface = Factory::getSistema();
/*
 0 - Invitado
 1 - Usuario
 2 - Administrador
 */
int tipoUsuario;
string nickName;

/*  PANTALLA INICIAL  */
void pantallaInicial(){
    cout << "································"<<endl;
    cout << "································"<<endl;
    cout << "································"<<endl;
    cout << "0 - Ver info Pelicula." << endl;
    cout << "1 - Ver comentarios y puntaje de pelicula." << endl;
    cout << "································"<<endl;
    cout << "2 - Crear Reserva."<<endl;
    cout << "3 - Puntuar Pelicula."<<endl;
    cout << "4 - Comentar Pelicula."<<endl;
    cout << "································"<<endl;
    cout << "5 - Alta Cine."<< endl;
    cout << "6 - Alta Funcion." << endl;
    cout << "7 - Eliminar Pelicula." << endl;
    cout << "8 - Logout ."<< endl;
    cout << "································"<<endl;
}



/*  PANTALLA LOGIN */
void casoLogin(){
    string pass;
    cout << "·····························" << endl;    
    cout << "·····························" << endl;    
    cout << "" << endl;        
    cout << "1 - Usuario: " << endl;
    cin >> nickName;
    cout << "2 - Pass: " << endl;
    cin >> pass;
    if (interface->login(nickName,pass)){
        cout << "Bienvenido " << nickName << endl;
        esAdmin = (nickName == "ale_ulises");
    }
}


int main()
{
    string entrada = "";
    do{
        do{
            pantallaAdmin()
        }while (entrada != "0" && entrada != "1" && entrada != "2" && entrada != "3");
        switch (entrada){
            case "0" : casoLogin(); break;
            case "1" : casoVerInfoPelicula(); break;
            case "2" : casoVerComentariosEInfoPelicula(); break;
            case "3" : casoTest(); break;
        }
        cas
        
cout <<        cines;
        
    }while(!entrada != "0");
    return 0;
}

void casoLogin(){
    pantallaLogin();
}