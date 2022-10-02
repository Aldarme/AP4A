//
// Created by rayan on 28/09/2022.
//

#ifndef UNTITLED72_HUMIDITY_H
#define UNTITLED72_HUMIDITY_H
#include "Sensor.h"


class Humidity : public Sensor<float>{
public:
    Humidity();
    ~Humidity();
    const SensorData& getData();

};
#endif //UNTITLED72_HUMIDITY_H
