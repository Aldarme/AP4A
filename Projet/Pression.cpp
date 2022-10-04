#ifndef PRESSION_CPP
#define PRESSION_CPP

#include "Pression.hpp"



void Pression::next()
{
    this->value = Sensor<int>::aleaGenVal();
}

#endif