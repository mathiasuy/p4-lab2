#ifndef DTUSUARIO_H
#define DTUSUARIO_H


class DtUsuario
{
    private:
        string nickName;
        string imagen;
        string password;
       
    public:
        DtUsuario();
        DtUsuario(string nickName, string imagen, string password);
        
        string getID();
        string getNickName();
        string getImagen();
        string getPassword();

        string toString(){

        virtual ~DtUsuario();
};

#endif // DTUSUARIO_H
