/**
* @author Alan HERVE
* @file Pression.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/


#ifndef PRESSION_HPP
#define PRESSION_HPP

#pragma once

#include "Sensor.hpp"
#include <iostream>



class Pression : public Sensor<int>
{
    private:
    
    const std::string name = "Pression";

    public:

    Pression()
    {
        this->m_type = 2;
        std::cout<< "   -> " <<this->name<<std::endl;
        this->m_value = aleaGenVal();
    }


    virtual ~Pression()
    {

    }


    /**
     * @brief gets the next value at random for this sensor
    **/
    void next();

};

#endif