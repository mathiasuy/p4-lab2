#include "include/ISistema.h"
#include "include/Factory.h"
#include <iostream>
#include <string>

#include <stdlib.h>
#include <stdexcept>
#include <stddef.h>
#ifdef _WIN32
#include <conio.h>
void clr()
{
    system("cls");
}
void readKey()
{
    cout << "\n";
    system("pause");
}
int readInt()
{
    int i;
    cin >> i;
    return i;
}
#else
void clr()
{
    system("clear men");
}
void readKey()
{
    system("read");
}
int readInt()
{
    int i;
    cin >> i;
    return i;
}
#endif



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
bool horaFijada = false;
bool datosCargados = false;
bool datosCargadosInCo = false;

/*  PANTALLA INICIAL  */
void pantallaInicial()
{
    cout << ((horaFijada)?interface->getFechaActual().toString() + " :)":"Hora no establecida :(") <<" -----"<< (tipoUsuario<1?"Bienvenido invitado!":" Sesion iniciada con el usuario: " + nickName) <<"\n"<< endl;
    cout << "*************************BIENVENIDO*************************"<<endl;
    cout << "************************************************************"<<endl;
    if (horaFijada)
    {
        cout << ((tipoUsuario>=0)?"1 - Ver info Pelicula.":"") << endl;
        cout << ((tipoUsuario>=0)?"2 - Ver comentarios y puntaje de pelicula.":"") << endl;
        cout << ((tipoUsuario>=0)?"------------------------------------------------------------\n":"");
        cout << ((tipoUsuario==1)?"3 - Crear Reserva.\n":"");
        cout << ((tipoUsuario==1)?"4 - Ver Reservas.\n":"");
        cout << ((tipoUsuario==1)?"5 - Puntuar Pelicula.\n":"");
        cout << ((tipoUsuario==1)?"6 - Comentar Pelicula.\n":"");
        cout << ((tipoUsuario==1)?"------------------------------------------------------------\n":"");
        cout << ((tipoUsuario==2)?"7 - Alta Cine.\n":"");
        cout << ((tipoUsuario==2)?"8 - Alta Funcion.\n":"");
        cout << ((tipoUsuario==2)?"9 - Eliminar Pelicula.\n":"");
        cout << ((tipoUsuario==2)?"------------------------------------------------------------\n":"");
        cout << ((tipoUsuario>=0)?"20 - Listar cines.":"") << endl;
        cout << ((tipoUsuario>=0)?"21 - Listar peliculas.":"") << endl;
        cout << ((tipoUsuario>=0)?"22 - Listar Funciones.":"") << endl;
        cout << ((tipoUsuario>=0)?"------------------------------------------------------------\n":"");
    }
    cout << "10 - " << ((tipoUsuario>0)?"Logout":"Login")<< endl;
    cout << ((tipoUsuario==0 && !datosCargados)?"11 - Test\n":"");
    cout << ((tipoUsuario==0 && !datosCargados)?"12 - Test InCo\n":"");
    cout << ((tipoUsuario==0)?((horaFijada)?"13 - Cambiar hora\n":"13 - Establecer hora\n"):"");
    cout << "0 - Salir." << endl;
    cout << "************************************************************" << endl;
}


/*  PANTALLA LOGIN */
void login()
{
    string pass;
    cout << "*******************************************" << endl;
    cout << "*******************************************" << endl;
    cout << "" << endl;
    cout << "1 - Usuario: " << endl;
    cin >> nickName;
    cout << "2 - Pass: " << endl;
    cin >> pass;

    cout << nickName << " " << pass;
    if (interface->login(nickName,pass))
    {
        clr();
        cout << "\n\n\n *** Bienvenido " << nickName << " *** " << endl;
        tipoUsuario = (nickName == "ale_ulises")?2:1;
    }
    else
    {
        cout << "Usuario/Clave no encontrado"<<endl;
    }
    readKey();
}



void imprimirComentarios(ListaDt<int,DtComentario> lc, int indice, int esRespuestaDeID)
{
//        cout << lc[i].toString() + "\n";
    int k = indice;
    if (k < lc.size())
    {
        while (k <= lc.size() && lc[indice].getID() != lc[k].getEsRespuestaDeID())
        {
            k++;
        }
        if (lc[k].getEsRespuestaDeID() != -1)
        {
            cout << "   ";
        }
        cout << "   " << lc[k].toString() << "\n";
        imprimirComentarios(lc,k+1,lc[k].getEsRespuestaDeID());
    }
}


int main()
{
    int opcion;
    nickName = "A";
    tipoUsuario = 1;
    horaFijada = true;

    do
    {
        clr();
        pantallaInicial();
        opcion = readInt();
        clr();

        switch (opcion)
        {
        /*****************************************************************/
        /*****************************************************************/
        /*****************************************************************/
        /*****************************************************************/
        /*****************************************************************/
        /*****************************************************************/
        /**********          VER INFO PELICULA  *************/
        /*****************************************************************/
        /*****************************************************************/
        case 1 :
            if (tipoUsuario>=0 && horaFijada)
            {
                cout << "/************ VER INFORMACION DE LA PELICULA... ************/ \n" <<endl;
//VER INFO PELICULA
                string titulo;
                ListaDt<string,DtPelicula> peliculas = interface->listarPeliculas();
                cout << "Cantidad de peliculas encontradas: " << peliculas.size() << endl;
                cout << "------------- " << endl;
                cout << peliculas.toString();
                cout << "------------- " << endl;
                cout << "Escriba el titulo de la pelicula que desea ver (o deje en blanco para cancelar):" <<endl;
                std::cin.ignore();
                getline (cin, titulo);
                if (titulo != "")// Si el usuario quiere cancelar, que aprete Enter (string vacio)
                {
                    /*  EN CASO mues-- */
                    DtPelicula p = peliculas[titulo];
                    cout << "------------- " << endl;
                    cout << p.toString();
                    cout << "------------- " << endl;
                    cout << "\nVer lista de cines con esa pelicula? (1-Si/ 2-No)"<<endl;
                    int e;
                    cin >> e;
                    if (e==1)
                    {
                        ListaDt<int,DtCine> cines = interface->listarCines(titulo);
                        cout << "Cantidad de Cines encontradas: " << cines.size() << endl;
                        cout << "------------- " << endl;
                        cout << cines.toString();
                        cout << "------------- " << endl;
                        cout << "Seleccione un cine:"<<endl;
                        int idCine;
                        cin >> idCine;
                        cout << "Listar funciones para ese cine?: (1- Si/ 2- No)"<<endl;
                        cin >> e;
                        if (e == 1)
                        {
                            //DtFecha f = interface->getFechaActual();
                            DtFecha f = DtFecha(12,6,2019,0,0);
                            ListaDt<int,DtFuncion> l = interface->listarFunciones(idCine,titulo,f);
                            cout << "Cantidad de Funciones encontradas: " << l.size() << endl;
                            cout << "------------- " << endl;
                            cout << l.toString();
                            cout << "------------- " << endl;
                            readKey();
                        }
                    }
                }
                //pantallaVerInfoPelicula(titulo);

            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /******          Ver comentarios y puntaje de pelicula  **********/
        /*****************************************************************/
        /*****************************************************************/
        /*  */
        case 2 :
            if (tipoUsuario>=0 && horaFijada)
            {
                cout << "/************ VER COMENTARIOS Y PUNTAJE DE LA PELICULA... ************/ \n" <<endl;
// VER COMENTARIOS Y PUNTAJE PELICULA
                string titulo;
                ListaDt<string,DtPelicula> listaDePeliculas = interface->listarPeliculas();

                //REVISEN DESDE ACAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
                listaDePeliculas.start();
                while(listaDePeliculas.end())
                {
                    cout << (listaDePeliculas.getElement()).getTitulo() + " " + (listaDePeliculas.getElement()).getPoster() << endl;
                    cout << "----------------------" << endl;
                    listaDePeliculas.next();
                }

                cout << "Escriba el titulo de la pelicula que desea ver (deja en blanco para cancelar):" <<endl;
                std::cin.ignore();
                std::getline(cin,titulo);
                //ACA NO DICE QUE EL USUARIO PUEDE CANCELAR
                if (titulo != "")
                {
                    DtPelicula p = listaDePeliculas[titulo];

                    //VOY A VER CUANTOS USUARIOS PUNTUARON ESA PELICULA PARA ESO NECESITO RECORRER
                    //LA COLECCION DE PUNTAJES DE ESA PELICULA
                    int a = interface->listarPuntajes(titulo).size(); //supuestamente aca devuelvo el total de usuarios que puntuaron la pelicula

                    //AHORA NECESITO LOS COMENTARIOS DE LA PELICULA

                    cout << p.getTitulo() <<endl;
                    cout << "Puntaje promedio: " << p.getPuntajePromedio() << " (" << a << " usuarios)"<<endl;
                    //ahora los comentarios
                    cout << "Comentarios: " <<endl;
                    ListaDt<int,DtComentario> lc = interface->listarComentarios(titulo);

                    //vector <DtComentario> aImprimir(NULL,lc.size());

                    vector<bool> impresos(false,lc.size());
                    for (int i = 1; i <= lc.size(); i++){
                            if (!impresos[i]){
                                  cout << lc[i].toString() + "\n";
                                  impresos[i] = true;
                            }
                            for (int k = i+1; k <= lc.size(); k++){
                                if (!impresos[k] && lc[i].getID() == lc[k].getEsRespuestaDeID()){
                                        if (lc[i].getEsRespuestaDeID() != -1){
                                            cout << "   ";
                                        }
                                        cout << "   " << lc[k].toString() << "\n";
                                        impresos[k] = true;
                                }
                            }
                    }



                    /*
                    int k = 1;
                    for (lc.start(); lc.end(); lc.next())
                    {
                        imprimirComentarios(lc,1,lc[k].getEsRespuestaDeID());
                        k++;
                    }
                    */

                    //Y AHORA FALTAN LOS PUNTAJES
                    cout << "Puntajes: " <<endl;
                    cout << interface->listarPuntajes(titulo).toString();
                    readKey();

                    //NO SE SI TERMINA ACA O QUE

                }
            };
            break;

        /*****************************************************************/
        /*****************************************************************/
        /**********          Crear Reserva   *************/
        /*****************************************************************/
        /*****************************************************************/



        case 3 :
            if (tipoUsuario==1 && horaFijada)
            {
                cout << "/************ CREAR RESERVA ************/ \n" <<endl;
//CREAR RESERVA

                int b = 1;
                while(b == 1)
                {
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
                        cout << "¿Ver lista de cines con esa pelicula?"<<endl;
                        cout << "1- Si." <<endl;
                        cout << "2- No." <<endl;

                        cin >> k;
                        if(k==1)
                        {
                            cout << interface->listarCines(titulo).toString();
                            cout << "Seleccione un cine:"<<endl;
                            cout << "0- Salir"<<endl;

                            cin >> e;
                            if (e != 0)
                            {
                                DtFecha f = interface->getFechaActual();
                                cout <<  interface->listarFunciones(e,titulo,f).toString();
                                cout << "Seleccione la funcion que desea reservar: "<<endl;
                                cout << "0- Salir."<<endl;
                                cin >> func;
                                if(func!=0)
                                {

                                    //AHORA CUANTOS ASIENTOS QUIERE
                                    cout << "Seleccione la cantidad de asientos que desea reservar: " <<endl;
                                    //ACA HAY QUE VER CON EXCEPCIONES QUE PONGA ASIENTOS MAYOR A 0, LUEGO LO VEO BIEN

                                    cin >>cantasien;
                                    cout << "Seleccione metodo de pago: " <<endl;
                                    cout << "1- Credito." <<endl;
                                    cout << "2- Debito." <<endl;

                                    cin >> tipotar;

                                    if(tipotar == 2)
                                    {
                                        cout << "Ingrese el nombre del banco que la emite: "<<endl;

                                        cin >> nombanc;
                                    }
                                    else
                                    {
                                        while(cantasien > 2)
                                        {
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
                                    cin >> confres;
                                    if(confres == 1)
                                    {
                                        bool res;//DEVUELVE SI SE REALIZO LA RESERVA O NO

                                        if(tipotar == 2) //DEBITO
                                        {
                                            ListaDt<int,DtFuncion>  a = interface->listarFunciones(e,titulo,f);
                                            //a[e].getPrecio();
                                            res=  interface->crearReserva(nickName, cantasien, func, nombanc, a[e].getPrecio());

                                        }//tipotar==2

                                        else   //ACA VA EL DESCUENTO, METI UNO INVENTADO PARA QUE COMPILE
                                        {

                                            float descuento = 0;
                                            if(nomfin == "OCA") {
                                                descuento = interface->getDescuento(nomfin);
                                            }

                                            res=  interface->crearReserva(nickName, cantasien, func, nomfin,descuento );

                                        }//else
                                        if(res)
                                        {
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
                                        else
                                        {
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
        /*****************************************************************/
        /*****************************************************************/
        /**********          Listar Reservas   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 4 :
            if (tipoUsuario==1 && horaFijada)
            {
                cout << "/************ LISTAR RESERVAS ************/ \n" <<endl;
                cout << "Se listan las reservas para el usuario " << nickName << endl;
                ListaDt<int,DtReserva> l = interface->listarReservas(nickName);
                cout << "Se encontraron " << l.size() << endl;
                cout << "---------------" << endl;
                cout << l.toString() << endl;
                cout << "---------------" << endl;
                readKey();
            };
            break;


        /*****************************************************************/
        /*****************************************************************/
        /**********          Puntuar Pelicula   *************/
        /*****************************************************************/
        /*****************************************************************/

         case 5 :
            if (tipoUsuario==1 && horaFijada) //PUNTUAR PELICULA
            {
                cout << "/************ PUNTUAR PELICULA ************/ \n" <<endl;
                //DECLARACIONES DE VARIABLES
                string nomPelicula;
                int respuesta;
                float puntajeNuevo;

                ListaDt<string, DtPelicula> peliculas = interface->listarPeliculas();
                cout << peliculas.toString();
                cout << "Ingrese el nombre de la película que desea puntuar: "<<endl;
                std::cin.ignore();
                std::getline(cin,nomPelicula);
                //DtPelicula p = peliculas[nomPelicula];
                if (interface->getPuntajePelicula(nickName, nomPelicula) != -1)
                {
                    cout << "Su actual puntaje a esta película es: " + Utils::aString(interface->getPuntajePelicula(nickName, nomPelicula)) << endl; //CREO QUE FALTA UN "BARRA" N ACA
                    cout << "Desea modificar el puntaje de la pelicula?    1- Sí       2- No "<<endl;
                    cin >> respuesta;

                    if (respuesta == 1)
                    {
                        cout << "Ingrese el nuevo puntaje de la pelicula"<<endl;
                        cin >> puntajeNuevo;
                        while (puntajeNuevo > 5) {
                            cout << "El puntaje no puede ser superior a 5. Ingrese el nuevo puntaje de la pelicula"<<endl;
                        cin >> puntajeNuevo;
                        } 
                        interface->puntuarPelicula(nickName, nomPelicula, puntajeNuevo);
                    }else{
                        readKey();
                    }
                }
                //SI ENTRO ACA ES PORQUE NO TENIA NINGUN PUNTAJE ESA PELICULA (ACORDARSE QUE RETORNA -1 SI NO ESTA PUNTUADA)
                else
                {
                    cout << "Ingrese el nuevo puntaje de la pelicula"<<endl;
                    cin >> puntajeNuevo;
                     while (puntajeNuevo > 5) {
                            cout << "El puntaje no puede ser superior a 5. Ingrese el nuevo puntaje de la pelicula"<<endl;
                        cin >> puntajeNuevo;
                        } 
                    interface->puntuarPelicula(nickName, nomPelicula, puntajeNuevo);
                }      //END ELSE

            }; //END CASO DE USO
            break;

        /*****************************************************************/
        /*****************************************************************/
        /**********          Comentar Pelicula   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 6 :
            if (tipoUsuario==1 && horaFijada)   //CASO DE USO COMENTAR PELICULA
            {
                cout << "/************ COMENTAR PELICULA ************/ \n" <<endl;
                //CASO DE USO COMENTAR PELICULA
                string nomPelicula, come; //DECLARACION DE VARIABLES
                int respuesta, esRespuestaDeID;
                bool hecho;

                ListaDt<string, DtPelicula> peliculas = interface->listarPeliculas();
                cout << peliculas.toString();
                cout << "Ingrese el nombre de la película que desea comentar: " <<endl;
                std::cin.ignore();
                std::getline(cin,nomPelicula);
                do
                {
                    ListaDt<int,DtComentario> comentarios = interface->listarComentarios(nomPelicula);
                    cout << comentarios.toString();
                    cout << "Que acción desea realizar?   1- Comentar       2- Responder comentario     3- Salir" <<endl;
                    cin >>respuesta;
                    if  (respuesta == 1)
                    {
                        cout << "Ingrese su comentario:" <<endl;
                        std::cin.ignore();
                        std::getline(cin,come);
                        hecho = interface->comentarPelicula(nickName, nomPelicula, come);
                        cout << "Comentario ingresado correctamente !" <<endl;
                    }
                    else if (respuesta == 2)
                    {
                        cout << "Ingrese el ID de el comentario que desea responder:" <<endl;
                        cin >> esRespuestaDeID;
                        cout << "Ingrese su comentario: " <<endl;
                        std::cin.ignore();
                        std::getline(cin,come);
                        hecho = interface->comentarPelicula(nickName, nomPelicula, come, esRespuestaDeID);
                    }
                }
                while (respuesta != 3);




            };

            break;

        /*****************************************************************/
        /*****************************************************************/
        /**********          Comentar Pelicula   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 6 :
            if (tipoUsuario==1 && horaFijada)   //CASO DE USO COMENTAR PELICULA
            {
                cout << "/************ COMENTAR PELICULA ************/ \n" <<endl;
                //CASO DE USO COMENTAR PELICULA
                string nomPelicula, come; //DECLARACION DE VARIABLES
                int respuesta, esRespuestaDeID;
                bool hecho;

                ListaDt<string, DtPelicula> peliculas = interface->listarPeliculas();
                cout << peliculas.toString();
                cout << "Ingrese el nombre de la película que desea comentar: ";
                std::cin.ignore();
                std::getline(cin,nomPelicula);
                do
                {
                    ListaDt<int,DtComentario> comentarios = interface->listarComentarios(nomPelicula);
                    cout << comentarios.toString();
                    cout << "Que acción desea realizar?   1- Comentar       2- Responder comentario     3- Salir";
                    cin >>respuesta;
                    if  (respuesta == 1)
                    {
                        cout << "Ingrese su comentario:";
                        std::cin.ignore();
                        std::getline(cin,come);
                        hecho = interface->comentarPelicula(nickName, nomPelicula, come);
                        cout << "Comentario ingresado correctamente !";
                    }
                    else if (respuesta == 2)
                    {
                        cout << "Ingrese el ID de el comentario que desea responder:";
                        cin >> esRespuestaDeID;
                        cout << "Ingrese su comentario: ";
                        std::cin.ignore();
                        std::getline(cin,come);
                        hecho = interface->comentarPelicula(nickName, nomPelicula, come, esRespuestaDeID);
                    }
                }
                while (respuesta != 3);




            };

            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          Alta Cine   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 7 :
            if (tipoUsuario==2 && horaFijada)
            {
                cout << "/************ DAR DE ALTA CINES ************/ \n" <<endl;
//CREAR CINE
                bool seguirAgregando = true;
                bool a;
                string titulo;
                int asientos, res;

                cout << "Escriba la direccion del cine: " << endl;
                std::cin.ignore();
                std::getline(cin,titulo);

                //Creo vector donde ingreso las salas
                vector<int> v1;
                //bucle para ir preguntando por salas
                while (seguirAgregando)
                {
                    cout << "Escriba la cantidad de asientos que tiene la sala: " << endl;
                    cin >> asientos;
                    v1.push_back(asientos);
                    cout << "¿Desea seguir agregando salas? " << endl;
                    cout <<"1- Si."<<endl;
                    cout <<"2- No."<<endl;
                    cin >> res;
                    if(res == 2)
                    {
                        seguirAgregando = false;
                    }
                }
                cout << "¿Desea confirmar el alta del nuevo cine? " <<endl;
                cout <<"1- Si."<<endl;
                cout <<"2- No."<<endl;
                cin >> res;
                if(res == 1)
                {
                    a = interface->altaCine(titulo, v1);
                };
                if (a)
                {
                    cout << "*****El Cine se agrego correctamente*****" << endl;
                };
            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          Alta Funcion   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 8 :
            if (tipoUsuario==2 && horaFijada)
            {
                cout << "/************ DAR DE ALTA FUNCIONES ************/ \n" <<endl;
//ALTA FUNCION
                string titulo, titulo2;
                int res, id, dia, mes, anio, minuto, hora;
                float precio;
                //Listar peliculas
                ListaDt<string,DtPelicula> peliculas = interface->listarPeliculas();
                cout << peliculas.toString();
                cout << "Escriba el titulo de la pelicula donde desea agregar una funcion:" << endl;
                std::cin.ignore();
                std::getline(cin,titulo);
                //Listar cines con esa pelicula
                ListaDt<int,DtCine> cines = interface->listarCines(titulo);
                cout << cines.toString();
                cout << "Escriba el cine donde desea agregar una funcion:" << endl;
                cin >> id;
                ListaDt<int,DtSala> salas = interface->listarSalas(id);
                //Listar salas x cine con esa pelicula
                cout << salas.toString();   //poner cantidad de asientos libres y ocupados
                cout << "Escriba la sala donde desea agregar una funcion:" << endl;
                cin >> res;

                //ingresa fecha y hora
                cout << "Ingrese el año: "<<endl;
                cin >> anio  ;
                cout << "Ingrese el mes: "<<endl;
                cin >> mes  ;
                cout << "Ingrese el dia: "<<endl;
                cin >> dia ;
                cout << "Ingrese la hora: "<<endl;
                cin >> hora  ;
                cout << "Ingrese los minutos: "<<endl;
                cin >> minuto  ;
                DtFecha f = DtFecha(dia, mes, anio, hora, minuto);

                //VERIFICAR
                cout << "Ingrese el precio de la entrada: "<<endl;
                cin >> precio;

                //cout <<((interface->altaFuncion(precio, f, res, id, titulo)?"La pelicula se elimino con exito.":"No se pudo eliminar")<<endl;
            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          Eliminar Pelicula   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 9 :
            if (tipoUsuario>0 && horaFijada)
            {
                cout << "/************ ELIMINAR PELICULA ************/ \n" <<endl;
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
                while (res != 1 && res != 2)
                {
                    cin >> res;
                }
                if(res == 1)
                {
                    cout <<((interface->eliminarPelicula(p.getTitulo()))?"La pelicula se elimino con exito.":"No se pudo eliminar")<<endl;
                }
            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          LOGOUT   *************/
        /*****************************************************************/
        /*****************************************************************/

        case 10 :
            if (tipoUsuario>0)
            {
                cout << "/************ SESION CERRADA ************/ \n" <<endl;
                tipoUsuario = 0;
                nickName = "";
                cout << "" << endl;
                cout << "" << endl;
                cout << "CHAU." << endl;
            }
            else
            {
                login();
            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          SALIR   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 0 :
            if (tipoUsuario>=0)
            {
                cout << "" << endl;
                cout << "" << endl;
                cout << "CHAU." << endl;
            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          TEST   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 11 :
            if (tipoUsuario>=0 && !datosCargados)
            {
                datosCargados = true;
                interface->test();
                cout << "Datos cargados correctamente." << endl;
            };
            break;

        /*****************************************************************/
        /*****************************************************************/
        /**********          TEST   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 12 :
            if (tipoUsuario>=0 && !datosCargadosInCo)
            {
                datosCargadosInCo = true;
                cout << "Test InCo.";
                interface->testInCo();
            };
            break;

        /*****************************************************************/
        /*****************************************************************/
        /**********          CAMBIAR HORA   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 13 :
            if (tipoUsuario==2)
            {
                cout << "/************ "<< ((horaFijada)?"CAMBIAR HORA":"ESTABLECER HORA") <<" ************/ \n" <<endl;
                /* cambiar hora */
                cout << "No implementado.";
                horaFijada = true;
            };
            break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          LISTAR CINES   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 20 :
        {
            cout << "/************ LISTADO DE TODOS LOS CINES ************/ \n" <<endl;
            cout << interface->listarCines().toString();
        }


        break;
        /*****************************************************************/
        /*****************************************************************/
        /**********          LISTAR PELICULAS   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 21 :
        {
            cout << "/************ LISTADO DE TODAS LAS PELICULAS ************/ \n" <<endl;
            cout << interface->listarPeliculas().toString();
        }
        break;
        /*****************************************************************/
        /*****************************************************************/
        /**********         LISTAR FUNCIONES   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 22 :
        {
            cout << "/************ LISTADO DE TODAS LAS FUNCIONES ************/ \n" <<endl;
            ListaDt<int,DtFuncion> l = interface->listarFunciones();

            cout << "La lista tiene " << l.size() << " funciones" << endl;
            cout << "" << l.toString() << endl;
        }


        break;
        /*****************************************************************/
        /*****************************************************************/
        /**********         SET USER   *************/
        /*****************************************************************/
        /*****************************************************************/
        case 30 :
        {
            cout << "/************ SET USER ************/ \n" <<endl;
            cin >> tipoUsuario;
        }


        break;
        default:
            cout << "\n\n/************ OPCION INCORRECTA!  O.O ************/ \n" <<endl;

        }
//
//        if (opcion != 0 && opcion != 30 && opcion != 10)
//            readKey();
    }
    while(opcion != 0);

    return 0;
}
