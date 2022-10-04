/**
 * @author Tontsa apala frank
 * @file Humidity.hpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */

#include <iostream>
#include "Sensor.hpp"
#ifndef HUMIDITY_H
#define HUMIDITY_H

class Humidity : public Sensor{

   public : Humidity():Sensor(){};   
    
    public : Humidity(const Humidity& H);

~Humidity();

};

#endif // HUMIDITY_H
