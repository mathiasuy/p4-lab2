#include "../include/Factory.h"
#include "../include/ISistema.h"
#include "logica/Sistema.h"

ISistema* Factory::getSistema(){
    Sistema* s = Sistema::getInstance();
    return s;
};

