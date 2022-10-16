//
// Created by rayan on 05/10/2022.
//

#ifndef PROJET_LIGHT_H
#define PROJET_LIGHT_H

#include "sensor.h"

class Light : public Sensor<bool>
{
public:
    Light();
    virtual ~Light();
    const SensorData& getData();
};

#endif //PROJET_LIGHT_H
