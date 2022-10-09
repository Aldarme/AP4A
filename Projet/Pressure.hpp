#ifndef PRESSURE_H
#define PRESSURE_H

#include <iostream>
#include "Sensor.hpp"

class pressure : public sensor
{
public:
    sensor getAlea();
};

#endif //PRESSURE_H