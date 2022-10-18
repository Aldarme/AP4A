/**
* @author MOhana wael
* @file : Light.hpp
* @date 27/09/2022
* @Description Declaration classe Light
*/

#include <iostream>
#include "./Sensor.hpp"
#ifndef Light_h
#define Light_h

class Light : public Sensor<bool>{

/***************CONSTRUCTORS***************/

//Default constructor
    public : Light();
//Constructor parametre
    public : Light(bool);
//Constructor par recopie
    public : Light(const Light& autre);

/***************METHODS***************/
//gen random val
virtual void aleaGenVal();

/***************DESTRUCTOR***************/
virtual ~Light();

};


#endif