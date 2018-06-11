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
    cout << ((tipoUsuario==1)?"4 - Ver Reservas.\n":"");
    cout << ((tipoUsuario==1)?"5 - Puntuar Pelicula.\n":"");
    cout << ((tipoUsuario==1)?"6 - Comentar Pelicula.\n":"");
    cout << " ································"<< endl;
    cout << ((tipoUsuario==2)?"7 - Alta Cine.\n":"");
    cout << ((tipoUsuario==2)?"8 - Alta Funcion.\n":"");
    cout << ((tipoUsuario==2)?"9 - Eliminar Pelicula.\n":"");
    cout << "································"<<endl;
    cout << "10 - " << ((tipoUsuario>0)?"Logout":"Login")<< endl;
    cout << "12 - " << ((tipoUsuario==0)?"Test\n":"")<< endl;
    cout << "13 - " << ((tipoUsuario>=0)?"Cambiar hora\n":"")<< endl;

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

                          string titulo;
                        ListaDt<string,DtPelicula> listaDePeliculas = interface->listarPeliculas();

                        //REVISEN DESDE ACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
                        listaDePeliculas.start();
                        while(listaDePeliculas.end()){
                         string texto = (listaDePeliculas.getElement()).getTitulo() + (listaDePeliculas.getElement()).getPoster();
                         cout << texto;
                        }

                          cout << "Escriba el titulo de la pelicula que desea ver:" <<endl;
                          getline (cin, titulo);
                          //ACA NO DICE QUE EL USUARIO PUEDE CANCELAR
                          DtPelicula p = interface->getPelicula(titulo);
                          //VOY A VER CUANTOS USUARIOS PUNTUARON ESA PELICULA PARA ESO NECESITO RECORRER
                          //LA COLECCION DE PUNTAJES DE ESA PELICULA
                          int a = interface->listarPuntajes(titulo).size(); //supuestamente aca devuelvo el total de usuarios que puntuaron la pelicula
                          //AHORA NECESITO LOS COMENTARIOS DE LA PELICULA interface->ListarComentarios(titulo).toString;
                          cout << p.getTitulo() <<endl;
                          cout << "Puntaje promedio: " << p.getPuntajePromedio() << " (" << a << " usuarios)"<<endl;
                          //ahora los comentarios
                          cout << "Comentarios" <<endl;
                          cout << interface->listarComentarios(titulo).toString();
                          //Y AHORA FALTAN LOS PUNTAJES
                          cout << "Puntajes" <<endl;
                          cout << interface->listarPuntajes(titulo).toString();

                             //NO SE SI TERMINA ACA O QUE

                             };
                        break;
            case 3 : if (tipoUsuario==1){
                          //CREAR RESERVA
                          int ciclo = 1;
                          while(ciclo){
                           string titulo;
                            cout << interface->listarPeliculas().toString();

                            cout << "Escriba el titulo de la pelicula que desea ver:" <<endl;
                            getline (cin, titulo);
                            if (titulo != "")// Si el usuario quiere cancelar, que aprete Enter (string vacio)
                            {   /*  EN CASO mues-- */
                                DtPelicula p = interface->getPelicula(titulo);
                                cout << p.getPoster();
                                cout << p.getSinopsis();
                                cout << "Ver lista de cines con esa pleicula?";
                                cout << "1- Si." <<endl;
                                cout << "2- No." <<endl;
                                bool k;
                                cin >> k;
                                if(k==1){
                                  cout << interface->listarCines(titulo).toString();

                                cout << "Seleccione un cine:"<<endl;
                                cout << "0- Salir"<<endl;
                                int e;
                                cin >> e;
                                if (e != 0){
                                    DtFecha f = interface->getFechaActual();
                                    interface->listarFunciones(e,titulo,f);
                                cout << "Desea repetir este proceso para otra película?" <<endl;
                                cout <<"1- Si." <<endl;
                                cout <<"2- No." <<endl;
                                int l;
                                cin >> l;
                                if(l==0){
                                ciclo = 0;
                                }
                                }
                       }


                       }//SI NO QUIERE VER CINES PARA LA PELICULA
                      else ciclo = 0; //no entra mas
                      }
            //HASTA ACA SERIA COMO EL VER INFO PELICULA AUNQUE TRATE DE ARREGLARLO UN POCO, MIRENLO


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

                        };
                        break;
            case 10 : if (tipoUsuario>=0){
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
