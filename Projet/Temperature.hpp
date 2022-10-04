/**
* @author Alan HERVE
* @file Temperature.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/


#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#pragma once

#include <iostream>
#include "Sensor.hpp"

using namespace std;



class Temperature : public Sensor<int>{
    
    private:
    
    const std::string name = "Temperature";
    
    public:
    
    Temperature()
    {
        
        cout<< "   -> " <<this->name<<endl;
        this->type = 3;
        this->value = Sensor<int>::aleaGenVal();
    }

    ~Temperature(){

    }

    void next();
};

#endif