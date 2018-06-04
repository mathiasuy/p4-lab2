#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <string>
using namespace std;

class DtComentario
{
private:
    int id;
    string nickName;
    string comentario;
    int esRespuestaDeID;
public:
        int getID();
        string getNickName();
        string getComentario();
        int getEsRespuestaDeID();
        bool isEqual(DtComentario* comentario);
        DtComentario(string nickName, string comentario);
        DtComentario(string nickName, string comentario, int esRespuestaDeID);

        ~DtComentario();
};

#endif // DTCOMENTARIO_H
