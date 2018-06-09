#ifndef DTCINE_H
#define DTCINE_H
#include <vector>
#include <string>

using namespace std;


    class DtCine
    {
        private:
            int id;
            string direccion;

         public:
            DtCine();
            DtCine(int id, string direccion);

            int getID();
            string getDireccion();
            bool isEqual(DtCine dtCine);
            string toString();

            virtual ~DtCine();

    };

#endif // DTCINE_H
