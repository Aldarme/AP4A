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
#include <random> //For the randomValue method
#include <tuple> //For the getData method
#include "Temperature.hpp" 
#include "Light.hpp"
#include "Pression.hpp"
#include "Humidity.hpp" //Is this really necessary to include them ?


template <class T> //template class with constructor
class Sensor
{

protected:
    Sensor();
    ~Sensor();
    virtual T randomValue(T param_minor, T param_major)=0; //Generating a random value between param_minor and param_major
    virtual T getData()=0; //Returning the data
};

/*
T Sensor::randomValue(T param_minor, T param_major)
{
    srand((unsigned)time(NULL));
    return (rand()%param_major - param_minor)+param_minor;
}; //Generating a random float between param_minor and param_major ?
*/


#endif //SENSOR_HPP



