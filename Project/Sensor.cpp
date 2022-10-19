/**
 * @author Muna Ayuni MAHATHIR
 * @file Sensor.cpp
 * @brief This is the implementation of class Sensor and all its child classes.
 */

#include "Sensor.hpp"
#include <iostream>
#include <math.h>


//This is a function of class Light which generates random value, either 0 or 1 
bool Light::aleagenval()
{
    int data= (rand()%2) ;
    if (data==0) return false ; 
    else return true ; 
}

//This is a function of class Humidity which generates random value, from 1% to 20%
float Humidity::aleagenval()
{
    float data ;
    int max = 20 ;
    int min = 1 ;
    data= ((max - min) * ((float)rand() / RAND_MAX)) + min;
    return data ; 

}

//This is a function of class Temperature which generates random value, from 22°C to 26°C 
float Temperature::aleagenval()
{
    float data ;
    int max = 26 ;
    int min = 22 ;
    data= ((max - min) * ((float)rand() / RAND_MAX)) + min;
    return data; 
}


//This is a function of class Pression which generates random value, from 540 hPa to 650hPa 
int Pression::aleagenval()
{
    int data= 540+ (rand() % 110)  ;
    return data;

}

