/**
* @author Alan HERVE
* @file Humidity.hpp
* @date 01/10/2022
* @brief Child class of Sensor
**/



#ifndef HUMIDTY_H
#define HUMIDITY_H

#include <iostream>
#include "Sensor.cpp"

using namespace std;


class Humidity : public Sensor<float>
{

    private:
    
    const std::string name = "Humidity";

    public:

    Humidity()
    {
        cout<< "   -> " <<this->name<<endl;
        this->type = 0;
        this->value = Sensor<float>::aleaGenVal();
    }

    ~Humidity()
    {

    }

    void next();
};

#endif
