
#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "../hpp/Sensor.hpp"
#endif

#include <string>
#include <cstdlib>
#include <ctime>

Sensor::Sensor(){
}

Sensor::~Sensor()
{
}



int Sensor::aleaGenVal(){
    int randomNumber = rand() % 10 + 1;
    return randomNumber;
}


int Sensor::getData(){
    return data;
}