#ifndef COMENTARIO_H
#define COMENTARIO_H
#include "DtComentario.h"

#include <string>
using namespace std;

class Comentario
{
    private:
        int id;
        string nickName;
        string comentario;
        int esRespuestaDeId;
        static int idGlobal;

    public:
        void setEsRespuestaDeId(int id);
        void setComentairo(string);

        DtComentario getDtComentario();
        string getComentario();
        int getEsRespuestaDeId();
        int getID();
        string toString();
        bool isEqual(Comentario* comentario);

        Comentario(int id, string nickName, string comentario);
        Comentario(int id, string nickName, string comentario, int esRespuestaDeId);
        virtual ~Comentario();
};

#endif // COMENTARIO_H
