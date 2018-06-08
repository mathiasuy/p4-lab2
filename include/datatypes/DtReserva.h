#ifndef DTRESERVA_H
#define DTRESERVA_H


class DtReserva
{
   private:
        int id;
        int cantAsientos;
        
    public:
        DtReserva();
        DTReserva(int id, int cantAsientos);
        /**         * Crear Reserva para pago con tarjeta de Credito         */
        DtReserva(int id, int cantAsientos, string financiera, float montoTotal, float descuento);
        /*** Crear Reserva para pago con tarjeta de Debito*/
        DtReserva(int id, int cantAsientos, string  banco, float montoTotal);
    
        int getID();
        int getCantAsientos();
       
        bool isEqual(Reserva * reserva);
        string toString();

        virtual ~DtReserva();
};

#endif // DTRESERVA_H
