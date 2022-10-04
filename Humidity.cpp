
#include <iostream>
#include <cstdio>
#include "Sensor.hpp"
#include "Humidity.hpp"
using namespace std;

Humidity::Humidity()
{
    min = 0;
    max = 100;
    (*this).value = aleaGenVal();
}

