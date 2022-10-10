///
///@author Gaspard Rochu
///@file Humitidy.hpp
///@date 04/10/2022
///@brief Class derivated from Sensor
///

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

#include <iostream>
#include "Sensor.hpp"

class Humidity: public Sensor
{
public :
    Humidity()=default; //I don't know why, by it don't work without this
    float getHumidity(); //creating a function to get the humidity %age
};

#endif //HUMIDITY_HPP