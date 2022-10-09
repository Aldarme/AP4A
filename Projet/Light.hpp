#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include "Sensor.hpp"

class light_ : public sensor
{
public:
    sensor getAlea();
};

#endif //LIGHT_H