#ifndef DTFECHA_H
#define DTFECHA_H


class DtFecha
{
    private:
    int dia;
    int mes;
    int anio;
    int minuto;
    int hora;

    public:
        DtFecha(); //asigna fecha de hoy
        DtFecha(int dia, int mes, int anio, int minuto, int hora);
        int getDia();
        int getMes();
        int getAnio();
        int getMinuto();
        int getHora();
        static DtFecha getFechaActual();
        virtual ~DtFecha();

    protected:


};

#endif // DTFECHA_H
DtFecha  DtFecha::getFechaActual(){
    time_t now = std::time(0);
    tm *ltm = localtime(&now);
    return DtFecha(1 + ltm->tm_mday,1 + ltm->tm_mon,1900 + ltm->tm_year);
}
