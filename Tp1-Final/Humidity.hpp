/**
* @author MOhana wael
* @file : Humidity.hpp
* @date 27/09/2022
* @Description Declaration classe humidity
*/

#include <iostream>
#include "./Sensor.hpp"

#ifndef Humidity_h
#define Humidity_h

class Humidity : public Sensor<float>{

/***************CONSTRUCTORS***************/
//Default constructor
    public : Humidity();
//Constructor parametre
    public : Humidity(float);
//Constructor par copie   
    public : Humidity(const Humidity&);

/***************METHODS***************/
//gen random val
virtual void aleaGenVal();

/***************DESTRUCTOR***************/
virtual ~Humidity();

};

#endif