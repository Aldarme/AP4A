/**
 * @author Muna Ayuni MAHATHIR
 * @file Sensor.cpp
 * @brief This is the implementation of class Sensor and all its child classes.
 */

#include "Sensor.hpp"
#include <iostream>
#include <math.h>

// GetData() is used to collects data from each sensor 
int Sensor::getdata( )
{
   return this->aleagenval() ;

}


//This is a function of class Light which generates random value, either 0 or 1 
int Light::aleagenval()
{
    int data= (rand()%2) ;
    return data;
}

//This is a function of class Humidity which generates random value, from 30% to 50%
int Humidity::aleagenval()
{
    int data= 30+ (rand() % 21) ;
    return data;

}

//This is a function of class Temperature which generates random value, from 22°C to 26°C 
int Temperature::aleagenval()
{
    int data= 22+ (rand() % 4)  ;
    return data;
}


//This is a function of class Pression which generates random value, from 540 hPa to 650hPa 
int Pression::aleagenval()
{
    int data= 540+ (rand() % 110)  ;
    return data;

}

