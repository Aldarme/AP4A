#ifndef TEMPERATURE_CPP
#define TEMPERATURE_CPP

#include "Temperature.hpp"


void Temperature::next()
{
    this->m_value = aleaGenVal();
}

#endif