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

class Light
{
private:
    static bool randomValue(int param_minor, int param_major); //0 and 1 for false and true
    
public :
    static bool getData();

    friend std::ostream &operator<<(std::ostream &os, const Light &light);
};

#endif //LIGHT_HPP