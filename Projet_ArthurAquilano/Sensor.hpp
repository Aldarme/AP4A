/**
 * @author Arthur
 * @file Sensor.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Sensor
 */


//DEFINE_GUARDS
#pragma once
#ifndef SENSOR_H
#define SENSOR_H

#include <cstdlib>
#include <time.h>


class Sensor
{
public:    
    int data;

    Sensor(): data(){};
    Sensor(const Sensor& s): data(s.data){};
    ~Sensor(){};
    
    int aleaGenVal(int minValue, int maxValue);   

    int getData();

};

#endif //SENSOR.H