#ifndef HUMIDITY_CPP
#define HUMIDITY_CPP

#include "Humidity.hpp"


void Humidity::next()
{
    this->value = aleaGenVal();
}

#endif