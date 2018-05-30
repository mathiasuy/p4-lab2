#include "../include/Utils.h"
#include <sstream> // stringstream
#include <iomanip> // setprecision
#include <iomanip> // setprecision
#include <sstream> // stringstream
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Utils::Utils()
{
    //ctor
}

Utils::~Utils()
{
    //dtor
}


std::string Utils::aString (int arg){

    // SALAS UNIX FING
    std::string ss =  std::to_string(arg);
    return ss;

/*
    // PARA MINGW
        char buffer[33];
        char* ss = itoa(arg,buffer,10);
        return std::string(ss);
*/
}

std::string Utils::aString (float arg){
    std::stringstream stream;
    stream << std::fixed << std::setprecision(4) << arg;
    return stream.str();
}
