#ifndef LIGHT_CPP
#define LIGHT_CPP

#include "LIGHT.h"


void Light::sense()
{
    this->value = Sensor<bool>::aleaGenVal();
}

#endif