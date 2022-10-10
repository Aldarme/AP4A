///
///@author Gaspard Rochu
///@file Light.hpp
///@date 04/10/2022
///@brief Class derivated from Sensor
///

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include "Sensor.hpp"

class Light: public Sensor
{
public :
    Light()=default; //I don't know why, by it don't work without this
    float getLight(); //creating a function to get the Light value
};

#endif //LIGHT_HPP