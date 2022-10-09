#include "Sensor.hpp"

int sensor::aleaGenVal()
{
    srand((unsigned int)time(0));
    return rand() % (max + 1 - min) + min;
}

sensor sensor::getData()
{
    data = aleaGenVal();
    return *this;
}