/**
* @author MOhana wael
* @file : Temperature.hpp
* @date 27/09/2020
* @Description Declaration classe Temperature
*/

#include <iostream>
#include "./Sensor.hpp"
#ifndef Temperature_h
#define Temperature_h

class Temperature : public Sensor<float>{

/***************CONSTRUCTORS***************/

//Default constructor
    public : Temperature();
//Constructor parametre
    public : Temperature(float);
//Constructor par recopie
    public : Temperature(const Temperature&);

/***************METHODS***************/
//gen random val
virtual void aleaGenVal();

/***************DESTRUCTOR***************/
virtual ~Temperature();

};

#endif