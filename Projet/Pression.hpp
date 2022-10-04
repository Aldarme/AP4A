/**
* @author Alan HERVE
* @file Pression.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/


#ifndef PRESSION_H
#define PRESSION_H

#pragma once

#include "Sensor.hpp"
#include <iostream>

using namespace std;

class Pression : public Sensor<int>
{
    private:
    
    const std::string name = "Pression";

    public:

    Pression()
    {
        cout<< "   -> " <<this->name<<endl;
        this->type = 2;
        this->value = Sensor<int>::aleaGenVal();
    }


    ~Pression()
    {

    }

    void next();

};

#endif