#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H
#include <string>

using namespace std;

class DtPuntaje {
private:
        string nickName;
        float puntaje;
public:
    DtPuntaje();
    DtPuntaje(string nickName, float puntaje);
   
    string getID();
    string getNickName();
    float getPuntaje();
    string toString();
   
    virtual ~DtPuntaje();
};

#endif /* DTPUNTAJE_H */

