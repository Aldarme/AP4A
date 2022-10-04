/**
* @author Alan HERVE
* @file Sensor.hpp
* @date 01/10/2022
* @brief Sensor class is the bases of the 4 classes : Temperature, Pression, Light, Humidity
**/


#ifndef SENSOR_H
#define SENSOR_H
#pragma once


#include <string>
#include <iostream>
#include <random>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function


using namespace std;


template <class Type> class  Sensor
{
    protected:
    std::string name;
    Type value; 
    
    private:
        
    public:
    int type;

    Sensor()
    {
        cout<<"Sensor class created with success ::"<<endl;
        
    }

    Sensor(const Sensor& copy)
    {

    }

    

    ~Sensor()
    {
        
    } 
    
    Type aleaGenVal();
    Type getData();
    
    
};




#endif