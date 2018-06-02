#ifndef MANEJADORUSUARIOS_H
#define MANEJADORUSUARIOS_H
#include "../logica/Usuario.h"
#include <map>

class ManejadorUsuarios
{
    private:
        static ManejadorUsuarios* instancia;
        map<string, Usuario*> usuarios;
        ManejadorUsuarios();
    public:

        /*  OPERACIONES */
        static ManejadorUsuarios* getInstancia();

        /*  OPERACIONES BASICAS */
        bool add(Usuario* cine);
        bool remove(string id);
        bool isMember(string id);
        Usuario* find(string id);
        bool isEmpty();

        /*  DESTRUCTOR */
        virtual ~ManejadorUsuarios();
};

#endif // MANEJADORUSUARIOS_H
