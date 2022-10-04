
#include <iostream>
#include <cstdio>
#include "Sensor.hpp"
#include "Temperature.hpp"
using namespace std;

Temperature::Temperature()
{
    min = 0;
    max = 50;
    (*this).value = aleaGenVal();
}

