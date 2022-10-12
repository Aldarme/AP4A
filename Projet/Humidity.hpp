/**
* @author Alan HERVE
* @file Humidity.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/



#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

#include <iostream>
#include "Sensor.hpp"



/// @brief 
class Humidity : public Sensor<float>
{

    private:
    
    const std::string name = "Humidity";

    public:

    Humidity()
    {
        std::cout<< "   -> " <<this->name<<std::endl;
        this->type = 0;
        this->value = aleaGenVal();
    }

    virtual ~Humidity()
    {

    }

    void next();
};

#endif