//
// Created by rayan on 05/10/2022.
//

#ifndef PROJET_PRESSION_H
#define PROJET_PRESSION_H
#include "sensor.h"

class Pression : public Sensor<float>
{
public:
    Pression();
    virtual ~Pression();
    const SensorData& getData();
};
#endif //PROJET_PRESSION_H
