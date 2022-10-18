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
    
    const std::string m_name = "Humidity";

    public:

    Humidity()
    {
        this->m_type = 0;
        std::cout<< "   -> " <<this->m_name<<std::endl;
        this->m_value = aleaGenVal();
    }

    virtual ~Humidity()
    {

    }


    /**
     * @brief gets the next value at random for this sensor
    **/
    void next();
};

#endif