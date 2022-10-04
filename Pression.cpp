
#include <iostream>
#include <cstdio>
#include "Sensor.hpp"
#include "Pression.hpp"
using namespace std;

Pression::Pression()
{
    min = 700;
    max = 1400;
    (*this).value = aleaGenVal();
}

