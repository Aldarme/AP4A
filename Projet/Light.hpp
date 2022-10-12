/**
* @author Alan HERVE
* @file Light.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/

#ifndef LIGHT_HPP
#define LIGHT_HPP
#pragma once

#include <iostream>

#include "Sensor.hpp"



class Light : public Sensor<bool>
{
    private:
    
    const std::string name = "Light";

    public:

    Light()
    {
        std::cout<< "   -> " <<this->name<<std::endl;
        this->type = 1;
        this->value = aleaGenVal();
    }

    virtual ~Light()
    {

    }


    /**
     * @brief gets the next value at random for this sensor
    **/
    void next();
};

#endif