#include "include/ISistema.h"
#include "include/Factory.h"

int main()
{
    ISistema* sistema = Factory::getSistema();

    cout << "Comienzo" << endl;

    sistema->login("Marcos","asd");
    cout << "login.. OK" << endl;
    int m[] = {3, 2, 1, 0, 4, 6, 7, 8};
    vector<int> v(m, m + sizeof(m) / sizeof (*m) );
    sistema->altaCine("MP",v);
    cout << "alta cine.. OK" << endl;
    DtFecha f;
    cout << "Test..." ;
    DtTest t = sistema->test();
    cout << "OK" << endl;
    cout << "Puntaje 1: " << t.getPuntaje1() << endl;
    cout << "Puntaje 1: " << t.getPuntaje2() << endl;

    return 0;
}
