#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <iostream>
#include "Sensor.hpp"

class humidity : public sensor
{
public:
    sensor getAlea();
};

#endif //HUMIDITY_H