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

class Pression: public Sensor
{
public :
    Pression()= default; //I don't know why, by it don't work without this
    float getPression(); //Creating a function to get the Pression in hPA
};

#endif //PRESSION_HPP