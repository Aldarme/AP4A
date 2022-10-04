/**
 * @author Tontsa apala frank
 * @file Temperature.hpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */
#include <iostream>
#include "Sensor.hpp"
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature : public Sensor{

    public : Temperature():Sensor(){};

    public : Temperature(const Temperature& T);

~Temperature();

};

#endif // TEMPERATURE_H
