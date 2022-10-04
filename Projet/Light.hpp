/**
* @author Alan HERVE
* @file Light.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/

#ifndef LIGHT_H
#define LIGHT_H
#pragma once

#include <iostream>

#include "Sensor.hpp"

using namespace std;

class Light : public Sensor<bool>
{
    private:
    
    const std::string name = "Light";

    public:

    Light()
    {
        cout<< "   -> " <<this->name<<endl;
        this->type = 1;
        this->value = Sensor<bool>::aleaGenVal();
    }

    ~Light()
    {

    }

    void next();
};

#endif