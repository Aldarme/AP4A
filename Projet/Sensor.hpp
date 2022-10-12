/**
* @author Alan HERVE
* @file Sensor.hpp
* @date 01/10/2022
* @brief Sensor class is the bases of the 4 classes : Temperature, Pression, Light, Humidity
**/


#ifndef SENSOR_HPP
#define SENSOR_HPP
#pragma once


#include <string>
#include <iostream>
#include <random>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function





template <class Type> class  Sensor
{
    protected:
    std::string name;
    Type value; 
    
    private:
        
    public:
    int type;

    Sensor() : 
    name(""),
    value(),
    type(0)
    {
        std::cout<<"Sensor class created with success ::"<<std::endl;
        
    }

    Sensor(const Sensor& copy) :
    name(""),
    value(),
    type(0)
    {

    }

    

    virtual ~Sensor()
    {
        
    } 
    

/**
* @brief Return a ranom number, method changes depending of the type of the class using this method
* @return int for Pression and Temperature, float for Humidity, bool for light
* @param . no parameter but uses template
**/
Type aleaGenVal()
{
   
    int temp_int;
    float temp_float;
    bool temp_bool;

    srand(time(NULL));

    switch (this->type)
    {
    case 0:
    {
        temp_float = (rand() % 101);
        temp_float = temp_float / 100;
        return temp_float;
    }break;
    case 1:
    {
        temp_bool = (rand() %11) < 5;
        return temp_bool;
    }break;
    case 2:
    {
        temp_int = (rand() % 3) + 7;
        return temp_int;
    }break;
    case 3:
    {
        temp_int = (rand() % 6) + 25;
        return temp_int;
    }break;
    default: 
        std::cout << "ERROR, USE METHOD 'aleaGenVal' ONLY FOR CHILD CLASSES OF SENSOR"<<std::endl;
        return 0;
        break;
    }



    return 0;
}

Type getData()
{
    
    return this->value;

}
         
    
};




#endif