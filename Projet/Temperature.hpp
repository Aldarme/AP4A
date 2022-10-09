#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include "Sensor.hpp"

class temperature : public sensor
{
public:
    sensor getAlea();
};

#endif // TEMPERATURE_H