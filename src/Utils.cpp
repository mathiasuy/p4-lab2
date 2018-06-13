#include "../include/Utils.h"


using namespace std;

Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}


std::string Utils::aString (int arg){
/*
    // SALAS UNIX FING y CYGWIN EN WINDOWS
    std::string ss =  std::to_string(arg);
    return ss;
*/

    // PARA MINGW EN WINDOWS
        char buffer[33];
        char* ss = itoa(arg,buffer,10);
        return std::string(ss);

}

std::string Utils::aString (float arg){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(4) << arg;
    return stream.str();
}
