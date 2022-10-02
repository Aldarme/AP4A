//
// Created by rayan on 28/09/2022.
//

#ifndef UNTITLED72_PRESSION_H
#define UNTITLED72_PRESSION_H
#include "Sensor.h"

class Pression : public Sensor<int>{

public:
    Pression();
    ~Pression();
    const SensorData& getData();

};
#endif //UNTITLED72_PRESSION_H
