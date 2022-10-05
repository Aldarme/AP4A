/**
* @author Alan HERVE
* @file Pression.cpp
* @date 01/10/2022
* @brief Child class of Sensor
**/

#ifndef PRESSION_CPP
#define PRESSION_CPP

#include "Pression.hpp"



void Pression::next()
{
    this->value = Sensor<int>::aleaGenVal();
}

#endif
