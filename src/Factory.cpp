#include "Factory.h"
#include "ISistema.h"
#include "logica/Sistema.h"

ISistema* Factory::getSistema(){
    Sistema* s = Sistema::getInstance();
    return s;
};

