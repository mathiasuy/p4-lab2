#ifndef DTTEST_H
#define DTTEST_H


class DtTest
{
    private:
        int puntaje1;
        int puntaje2;
    public:
        int getID();//poner que devuelva cualquier cualquier cosa, es para poder realizar test nomas
        int getPuntaje1();
        int getPuntaje2();

        DtTest();
        DtTest(int puntaje1, int puntaje2);
        virtual ~DtTest();
};

#endif // DTTEST_H
