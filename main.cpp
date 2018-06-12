#include "include/ISistema.h"
#include "include/Factory.h"
#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdexcept>
#include <stddef.h>


using namespace std;

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
    cout << "********************************"<<endl;
    cout << "********************************"<<endl;
    cout << "********************************"<<endl;
    cout << ((tipoUsuario>=0)?"1 - Ver info Pelicula.":"") << endl;
    cout << ((tipoUsuario>=0)?"2 - Ver comentarios y puntaje de pelicula.":"") << endl;
    cout << ((tipoUsuario>=0)?"20 - Listar cines.":"") << endl;
    cout << ((tipoUsuario>=0)?"21 - Listar peliculas.":"") << endl;
    cout << ((tipoUsuario>=0)?"22 - Listar Funciones.":"") << endl;
    cout << " *******************************"<<endl;
    cout << ((tipoUsuario==1)?"3 - Crear Reserva.\n":"");
    cout << ((tipoUsuario==1)?"4 - Ver Reservas.\n":"");
    cout << ((tipoUsuario==1)?"5 - Puntuar Pelicula.\n":"");
    cout << ((tipoUsuario==1)?"6 - Comentar Pelicula.\n":"");
    cout << " ********************************"<< endl;
    cout << ((tipoUsuario==2)?"7 - Alta Cine.\n":"");
    cout << ((tipoUsuario==2)?"8 - Alta Funcion.\n":"");
    cout << ((tipoUsuario==2)?"9 - Eliminar Pelicula.\n":"");
    cout << "********************************"<<endl;
    cout << "10 - " << ((tipoUsuario>0)?"Logout":"Login")<< endl;
    cout << "11 - " << ((tipoUsuario==0)?"Test\n":"")<< endl;
    cout << "13 - " << ((tipoUsuario>=0)?"Cambiar hora\n":"")<< endl;

    cout << "0 - Salir." << endl;
    cout << "********************************"<<endl;
}


/*  PANTALLA LOGIN */
void login(){
    string pass;
    cout << "*****************************" << endl;
    cout << "*****************************" << endl;
    cout << "" << endl;
    cout << "1 - Usuario: " << endl;
    cin >> nickName;
    cout << "2 - Pass: " << endl;
    cin >> pass;

    cout << nickName << " " << pass;
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
    tipoUsuario = 2;
    do{

        pantallaInicial();
        cin >> opcion;
        switch (opcion){
            case 1 : if (tipoUsuario>=0){
                            string titulo;
                            ListaDt<string,DtPelicula> peliculas = interface->listarPeliculas();
                            cout << peliculas.toString();

                            cout << "Escriba el titulo de la pelicula que desea ver:" <<endl;
                            std::cin.ignore();
                            getline (cin, titulo);
                            if (titulo != "")// Si el usuario quiere cancelar, que aprete Enter (string vacio)
                            {
                                /*  EN CASO mues-- */
                                DtPelicula p = peliculas[titulo];
                                cout << p.getPoster();
                                cout << p.getSinopsis();
                                cout << "Ver lista de cines con esa pelicula?"<<endl;
                                cout << "1- Si." <<endl;
                                cout << "2- No" << endl;
                                int e;
                                cin >> e;
                                if (e==1){
                                        ListaDt<int,DtCine> cines = interface->listarCines();
                            cout << cines.toString();

                                    cout << interface->listarCines(titulo).toString();
                                }
                                cout << "Seleccione un cine:";
                                cin >> e;
                                if (e == 1){
                                    DtFecha f = interface->getFechaActual();
                                    cout << interface->listarFunciones(e,titulo,f).toString();
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
                          cin >> titulo;
                          //ACA NO DICE QUE EL USUARIO PUEDE CANCELAR
                          DtPelicula p = listaDePeliculas[titulo];
                          //VOY A VER CUANTOS USUARIOS PUNTUARON ESA PELICULA PARA ESO NECESITO RECORRER
                          //LA COLECCION DE PUNTAJES DE ESA PELICULA
                          int a = interface->listarPuntajes(titulo).size(); //supuestamente aca devuelvo el total de usuarios que puntuaron la pelicula
                          //AHORA NECESITO LOS COMENTARIOS DE LA PELICULA interface->ListarComentarios(titulo).toString;
                          std::cout << "Press any key to continue . . ." << std::endl;

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


       int b = 1;
            while(b == 1){
          //VARIABLES
          string titulo;
          int k = 0;
          int e = 0;
          int func = 0;
          int cantasien = 0;
          int tipotar = 0;
          string nombanc;
          string nomfin;
          int confres = 0;

    ListaDt<string, DtPelicula> peliculas = interface->listarPeliculas();
   cout << peliculas.toString();
   cout << "Escriba el titulo de la pelicula que desea ver:" <<endl;
   std::cin.ignore();
   getline (cin, titulo);

    if (titulo != "")// Si el usuario quiere cancelar, que aprete Enter (string vacio)
      {
         DtPelicula p = peliculas[titulo];
         cout << p.getPoster();
         cout << p.getSinopsis();
         cout << "¿Ver lista de cines con esa pelicula?";
         cout << "1- Si." <<endl;
         cout << "2- No." <<endl;

         cin >> k;
           if(k==1){
                cout << interface->listarCines(titulo).toString();
                cout << "Seleccione un cine:"<<endl;
                cout << "0- Salir"<<endl;

                cin >> e;
            if (e != 0){
                    DtFecha f = interface->getFechaActual();
                    cout <<  interface->listarFunciones(e,titulo,f).toString();
                    cout << "Seleccione la funcion que desea reservar: "<<endl;
                    cout << "0- Salir."<<endl;
                     cin >> func;
                       if(func!=0){

                       //AHORA CUANTOS ASIENTOS QUIERE
                      cout << "Seleccione la cantidad de asientos que desea reservar: " <<endl;
                //ACA HAY QUE VER CON EXCEPCIONES QUE PONGA ASIENTOS MAYOR A 0, LUEGO LO VEO BIEN

                      cin >>cantasien;
                      cout << "Seleccione metodo de pago: " <<endl;
                      cout << "1- Credito." <<endl;
                      cout << "2- Debito." <<endl;

                      cin >> tipotar;

                      if(tipotar == 2){
                                   cout << "Ingrese el nombre del banco que la emite: "<<endl;

                                   cin >> nombanc;
                                   }
                                   else{
                                   while(cantasien > 2){
                                       cout << "No puede reservar mas de 2 asientos, por favor introduzca de nuevo la cantidad de asientos:"<<endl;
                                       cin >>cantasien;
                                   }
                                   //ACA YA PIDIO ASIENTOS BIEN
                                   cout << "Ingrese el nombre de la financiera que la emite: "<<endl;

                                   cin >> nomfin;
                                   }//else


                              //AHORA SE VA A CREAR LA RESERVA
                                  cout << "Quiere confirmar la reserva?" <<endl;
                                  cout<< "1- Si."<<endl;
                                  cout <<"2- No."<<endl;

                                      if(confres == 1){
                                                       bool res;//DEVUELVE SI SE REALIZO LA RESERVA O NO

                                                     if(tipotar == 2){//DEBITO
                                                       ListaDt<int,DtFuncion>  a = interface->listarFunciones(e,titulo,f);
                                                       //a[e].getPrecio();
                                                     res=  interface->crearReserva(nickName, cantasien, func, nombanc, a[e].getPrecio());

                                                        }//tipotar==2

                                                      else{  //ACA VA EL DESCUENTO, METI UNO INVENTADO PARA QUE COMPILE
                                                          float descuento = interface->getDescuento(nomfin);
                                                            res=  interface->crearReserva(nickName, cantasien, func, nomfin,descuento );

                                                           }//else
                                             if(res){
                                                     cout << "Su reserva se realizo con exito." <<endl;
                                                     cout << "¿Quiere realizar otra reserva para otra pelicula?"<<endl;
                                                     cout << "1- Si."<<endl;
                                                     cout << "2- No."<<endl;
                                                     /*int b;
                                                     cin >>b;
                                                     if(b == 2){
                                                      ciclo = 0;
                                                      }*/
                                                     }//res
                                             else{
                                                 cout << "No hay asientos disponibles para esta funcion."<<endl;
                                                 cout << "¿Quiere realizar otra reserva para otra pelicula?"<<endl;
                                                 cout << "1- Si."<<endl;
                                                 cout << "2- No."<<endl;
                                             }
                                             int b;
                                             cin >>b;
                                          }//confres


                        }//if func!=0


                        }//if e!=0


                     }//if k==1


                    }//if titulo

    else
        b = 2; //el usuario quiere salir
    }//while

};//case





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
                         //ELIMINAR PELICULA
                           string titulo;
                           ListaDt<string,DtPelicula> peliculas = interface->listarPeliculas();
                           cout << peliculas.toString();
                           cout << "Escriba el titulo de la pelicula que desea eliminar:" << endl;
                           std::cin.ignore();
                           std::getline(cin,titulo);
                           DtPelicula p = peliculas[titulo];
                           cout << "¿Seguro que desea eliminar " << p.getTitulo() <<"?" <<endl;
                           cout <<"1- Si."<<endl;
                           cout <<"2- No."<<endl;
                           int res;
                           cin >> res;
                           while (res != 1 && res != 2){
                               cin >> res;
                           }
                           if(res == 1){
                                cout <<((interface->eliminarPelicula(p.getTitulo()))?"La pelicula se elimino con exito.":"No se pudo eliminar")<<endl;
                           }
                        };
                        break;
            case 10 : if (tipoUsuario>0){
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
            case 20 :
                            cout << interface->listarCines().toString();
                        break;
            case 21 :
                            cout << interface->listarPeliculas().toString();
                        break;
            case 22 :
                            cout << interface->listarFunciones().toString();

                        break;

        }
    }while(opcion != 0);

    return 0;
}
