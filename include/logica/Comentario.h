#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "../datatypes/DtComentario.h"
#include "../Utils.h"

using namespace std;

class Comentario
{
    private:
        int id;
        string nickName;
        string comentario;
        int esRespuestaDeID;
        static int idGlobal;

    public:
        void setEsRespuestaDeID(int id);
        void setComentairo(string);

        DtComentario getDt();
        string getComentario();
        int getEsRespuestaDeID();
        int getID();
        string toString();
        bool isEqual(Comentario* comentario);

        Comentario(string nickName, string comentario);
        Comentario(string nickName, string comentario, int esRespuestaDeID);
        virtual ~Comentario();
};

#endif // COMENTARIO_H
