#include "../include/Factory.h"
#include "../include/logica/Sistema.h"

ISistema* Factory::getSistema(){
    return Sistema::getInstance();;
};
