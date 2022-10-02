//
// Created by rayan on 26/09/2022.
//

#ifndef UNTITLED72_TEMPERATURE_H
#define UNTITLED72_TEMPERATURE_H
#include "Sensor.h"
#include "../Enum.h"

class Temperature : public Sensor<float>{
public:
    Temperature();
    ~Temperature();
    const SensorData& getData();
};

#endif //UNTITLED72_TEMPERATURE_H
