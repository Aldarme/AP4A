/**
* @author Alan HERVE
* @file Temperature.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/


#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#pragma once

#include <iostream>
#include "Sensor.hpp"




class Temperature : public Sensor<int>{
    
    private:
    
    const std::string m_name = "Temperature";
    
    public:
    
    Temperature()
    {
        this->m_type = 3;
        std::cout<< "   -> " <<this->m_name<<std::endl;
        this->m_value = aleaGenVal();
    }

    virtual ~Temperature(){

    }

    /**
     * @brief gets the next value at random for this sensor
    **/
    void next();
};

#endif