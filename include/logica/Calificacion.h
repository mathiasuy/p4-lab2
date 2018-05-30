#ifndef PUNTAJE_H
#define PUNTAJE_H


class Puntaje
{
    private:
        string nickName;
        float puntaje;

    public:
        void setPuntaje(float puntaje);
        float getPuntaje();

        int getId();
        string toString();
        bool isEqual(Puntaje *puntaje);

        /* CONSTRUS Y DESTRUS */
        Puntaje();
        virtual ~Puntaje();
};

#endif // CALIFICACION_H
