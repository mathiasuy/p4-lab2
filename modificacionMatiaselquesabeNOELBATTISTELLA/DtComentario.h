#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H


class DtComentario
{

    private:
         string nickname;
         string comentario;
         int id;
         int esRespuestaDeId;

    public:
        DtComentario(string nickname, string comentario, int id, int esRespuestaDeId);
        DtComentario(string nickname, string comentario, int id);
        string getNickname();
        string getComentario();
        int getId();
        int getEsRespuestaDeId();
        bool isEqual(DtComentario dtComentario);
        string toString();

        virtual ~DtComentario();

    protected:


};

#endif // DTCOMENTARIO_H
