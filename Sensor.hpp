///
///@author Gaspard Rochu
///@file Sensor.hpp
///@date 04/10/2022
///@brief Superclass for Temperature, Humidity, Pression, Light, it also provide the getData method.
///

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <vector>
#include <random>
#include "Temperature.hpp" 
#include "Light.hpp"
#include "Pression.hpp"
#include "Humidity.hpp" //Is this really necessary to include them ?

class Sensor
{
protected :
    float randomValue(float a, float b); //function that generate a random value, used by the Sensors (Light, Pression, Humidity, Temperature)
public :
    static std::vector<float> getData(); //function that collect the datas

};

#endif //SENSOR_HPP



