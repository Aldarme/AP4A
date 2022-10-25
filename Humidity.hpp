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

class Humidity
{
private:
    static float randomValue(float param_minor, float param_major);
    
public:
    static float getData();

    friend std::ostream &operator<<(std::ostream &os, const Humidity &humidity);
};

#endif //HUMIDITY_HPP