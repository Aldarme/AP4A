//
// Created by rayan on 26/09/2022.
//

#ifndef UNTITLED72_SENSOR_H
#define UNTITLED72_SENSOR_H
#include <iostream>

class Sensor {
    private:

    public:
    Sensor();
    ~Sensor();
    Sensor(Sensor& sensor);
    float getData();
    float aleaGenVal();

};
#endif //UNTITLED72_SENSOR_H
