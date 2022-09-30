//
// Created by rayan on 26/09/2022.
//
#include <iostream>
#include "Sensor.h"

Sensor::Sensor() = default;
Sensor::~Sensor() = default;
Sensor::Sensor(Sensor &sensor) = default;

float Sensor::aleaGenVal() {
    float alea;
    alea=rand() % (100 - 0 + 1) + 0;
    return alea;
}

float Sensor::getData() {
    float data;
    data = this->aleaGenVal();
    return data;
}

