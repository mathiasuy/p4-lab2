#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>

using namespace std;

class DtReserva
{
   private:
        int id;
        int cantAsientos;
        
    public:
        DtReserva();
        DtReserva(int id, int cantAsientos);
    
        int getID();
        int getCantAsientos();
       
        bool isEqual(DtReserva* reserva);
        string toString();

        virtual ~DtReserva();
};

#endif // DTRESERVA_H
