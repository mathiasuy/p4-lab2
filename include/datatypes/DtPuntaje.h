#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H
#include <string>

class DtPuntaje {
private:
        std::string nickName;
        float puntaje;
public:
    DtPuntaje();
    DtPuntaje(std::string nickName, float puntaje);
   
    std::string getID();
    std::string getNickName();
    float getPuntaje();
   
    virtual ~DtPuntaje();
};

#endif /* DTPUNTAJE_H */

