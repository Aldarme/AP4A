///
///@author Gaspard Rochu
///@file Temperature.hpp
///@date 04/10/2022
///@brief Class derivated from Sensor
///

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#include <iostream>
#include "Sensor.hpp"

class Temperature: public Sensor
{
public :
    Temperature() = default; //I don't know why, by it don't work without this
    float getTemperature(); //Creating a function to get the temperature in °C
};

#endif //TEMPERATURE_HPP