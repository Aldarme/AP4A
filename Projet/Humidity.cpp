#ifndef HUMIDITY_CPP
#define HUMIDITY_CPP

#include "Humidity.hpp"


void Humidity::next()
{
    this->m_value = aleaGenVal();
}

#endif