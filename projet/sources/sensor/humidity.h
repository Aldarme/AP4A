#ifndef PROJET_HUMIDITY_H
#define PROJET_HUMIDITY_H
#include "sensor.h"

class Humidity : public Sensor<float>
{
public:
    Humidity();
    virtual ~Humidity();
    const SensorData& getData();

};

#endif //PROJET_HUMIDITY_H
