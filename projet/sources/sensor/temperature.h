#ifndef PROJET_TEMPERATURE_H
#define PROJET_TEMPERATURE_H
#include "sensor.h"

class Temperature : public Sensor<float>
{
public:
    Temperature();
    virtual ~Temperature();
    const SensorData& getData();
};

#endif //PROJET_TEMPERATURE_H
