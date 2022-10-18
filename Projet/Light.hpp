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
    
    const std::string m_name = "Light";

    public:

    Light()
    {
        this->m_type = 1;
        std::cout<< "   -> " <<this->m_name<<std::endl;
        this->m_value = aleaGenVal();
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