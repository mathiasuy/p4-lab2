#include "include/ISistema.h"
#include "include/Factory.h"
#include <iostream>

ISistema* interface = Factory::getSistema();
/*
 0 - Invitado
 1 - Usuario
 2 - Administrador
 */
int tipoUsuario;
string nickName;
string entrada;


/*  PANTALLA INICIAL  */
void pantallaInicial(){
    cout << "································"<<endl;
    cout << "································"<<endl;
    cout << "································"<<endl;
    cout << ((tipoUsuario>=0)?"1 - Ver info Pelicula.":"") << endl;
    cout << ((tipoUsuario>=0)?"2 - Ver comentarios y puntaje de pelicula.":"") << endl;
    cout << " ·······························"<<endl;
    cout << ((tipoUsuario==1)?"3 - Crear Reserva.\n":"");
    cout << ((tipoUsuario==1)?"4 - Puntuar Pelicula.\n":"");
    cout << ((tipoUsuario==1)?"5 - Comentar Pelicula.\n":"");
    cout << " ································"<< endl;
    cout << ((tipoUsuario==2)?"6 - Alta Cine.\n":"");
    cout << ((tipoUsuario==2)?"7 - Alta Funcion.\n":"");
    cout << ((tipoUsuario==2)?"8 - Eliminar Pelicula.\n":"");
    cout << "································"<<endl;
    cout << "9 - " << ((tipoUsuario>0)?"Logout":"Login")<< endl;
    cout << "11 - " << ((tipoUsuario==0)?"Test\n":"")<< endl;
    cout << "12 - " << ((tipoUsuario>=0)?"Cambiar hora\n":"")<< endl;

    cout << "0 - Salir." << endl;
    cout << "································"<<endl;
}


/*  PANTALLA LOGIN */
void login(){
    string pass;
    cout << "·····························" << endl;
    cout << "·····························" << endl;
    cout << "" << endl;
    cout << "1 - Usuario: " << endl;
    getline(cin,nickName);
    cout << "2 - Pass: " << endl;
    getline(cin,pass);
    if (interface->login(nickName,pass)){
        cout << "Bienvenido " << nickName << endl;
        tipoUsuario = (nickName == "ale_ulises")?2:1;
    }else{
        cout << "Error";
    }
}


int main()
{
        int opcion;
    tipoUsuario = 0;
    do{

        pantallaInicial();
        cin >> opcion;
        switch (opcion){
            case 1 : if (tipoUsuario>=0){
                            string titulo;
                            cout << interface->listarPeliculas().toString();
                            
                            cout << "Escriba el titulo de la pelicula que desea ver:" <<endl;
                            getline (cin, titulo);
                            if (titulo != "")// Si el usuario quiere cancelar, que aprete Enter (string vacio)
                            {
                                /*  EN CASO mues-- */
                                DtPelicula p = interface->getPelicula(titulo);
                                cout << p.getPoster();
                                cout << p.getSinopsis();
                                cout << "Ver lista de cines con esa pleicula?";
                                int e = 0;
                                cin >> e;
                                if (e==1){
                                    cout << interface->listarCines(titulo).toString();
                                }
                                cout << "Seleccione un cine:";
                                cin >> e;
                                if (e == 1){
                                    DtFecha f = interface->getFechaActual();
                                    interface->listarFunciones(e,titulo,f);
                                }
                            }
                            //pantallaVerInfoPelicula(titulo);

                        };
                        break;
            case 2 : if (tipoUsuario>=0){

                        };
                        break;
            case 3 : if (tipoUsuario==1){

                        };
                        break;
            case 4 : if (tipoUsuario==1){

                        };
                        break;
            case 5 : if (tipoUsuario==1){

                        };
                        break;
            case 6 : if (tipoUsuario==2){

                        };
                        break;
            case 7 : if (tipoUsuario==2){

                        };
                        break;
            case 8 : if (tipoUsuario==2){

                        };
                        break;
            case 9 : if (tipoUsuario>0){
                            tipoUsuario = 0;
                            nickName = "";
                            cout << "Hasta luego." << endl;
                        }else{
                            login();
                        };
                        break;
            case 0 : if (tipoUsuario>=0){
                            cout << "Hasta luego." << endl;
                        };
                        break;
            case 11 : if (tipoUsuario>=0){
                            interface->test();
                            cout << "Datos cargados correctamente." << endl;
                        };
                        break;
            case 12 : if (tipoUsuario>=0){
                            /* cambiar hora */

                        };
                        break;
        }
    }while(opcion != 0);

    return 0;
}
