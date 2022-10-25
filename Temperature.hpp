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

class Temperature
{
private:
    static float randomValue(float param_minor, float param_major);

public:
    static float getData();

    friend std::ostream &operator<<(std::ostream &os, const Temperature &temperature);
};

#endif //TEMPERATURE_HPP