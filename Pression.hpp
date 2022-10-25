///
///@author Gaspard Rochu
///@file Pression.hpp
///@date 04/10/2022
///@brief Class derivated from Sensor
///

#ifndef PRESSION_HPP
#define PRESSION_HPP

#include <iostream>
#include "Sensor.hpp"

class Pression
{
private:
    static int randomValue(int param_minor, int param_major);

public:
    static int getData();

    friend std::ostream &operator<<(std::ostream &os, const Pression &pression);
};

#endif //PRESSION_HPP