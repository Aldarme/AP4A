#ifndef LIGHT_CPP
#define LIGHT_CPP

#include "Light.hpp"


void Light::next()
{
    this->value = Sensor<bool>::aleaGenVal();
}

#endif