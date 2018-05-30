#ifndef FACTORY_H
#define FACTORY_H
#include "ISistema.h"

class Factory
{
    private:
        static ISistema* sistema;
    public:
        static ISistema* getSistema();
};

#endif // FACTORY_H
