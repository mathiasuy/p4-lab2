#ifndef LISTADT_H
#define LISTADT_H
#include <map>
#include "../datatypes/DtTest.h"
#include "../datatypes/DtCine.h"
#include "../datatypes/DtComentario.h"
#include "../datatypes/DtCredito.h"
#include "../datatypes/DtDebito.h"
#include "../datatypes/DtFecha.h"
#include "../datatypes/DtFuncion.h"
#include "../datatypes/DtPelicula.h"
#include "../datatypes/DtPuntaje.h"
#include "../datatypes/DtReserva.h"
#include "../datatypes/DtSala.h"
#include "../logica/Funcion.h"
#include "../logica/Comentario.h"
#include "../logica/Puntaje.h"

using namespace std;

namespace Util{

    template <typename K, typename T>
    class ListaDt{
        private:
            map<K,T> _map;
            typename map<K,T>::iterator i;
        public:
            void add(T t);
            void add(map<K,T> lista);
            void start();
            bool end();
            T& getElement();
            T& operator[] (K x){
                return this->_map[x];
            };
            void next();
    };

}

//  Otra forma de hacerlo:

    template class Util::ListaDt<string,DtPelicula>;
    template class Util::ListaDt<int,DtCine>;
    template class Util::ListaDt<int,DtComentario>;
    template class Util::ListaDt<int,DtReserva>;
    template class Util::ListaDt<int,DtFuncion>;
    template class Util::ListaDt<string,DtPuntaje>;
    template class Util::ListaDt<int,DtSala>;





#endif // LISTADT_H
