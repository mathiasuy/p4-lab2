#include "../../include/datatypes/DtTest.h"

DtTest::DtTest(int puntaje1, int puntaje2)
{
    this->puntaje1 = puntaje1;
    this->puntaje2 = puntaje2;
}

DtTest::DtTest()
{
    this->puntaje1 = 0;
    this->puntaje2 = 0;
}

DtTest::~DtTest()
{
    //dtor
}

        int DtTest::getPuntaje1(){
            return this->puntaje1;
        };

        int DtTest::getPuntaje2(){
            return this->puntaje2;
        };

        