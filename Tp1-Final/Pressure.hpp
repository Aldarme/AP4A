/**
* @author MOhana wael
* @file : Pressure.hpp
* @date 27/09/2022
* @Description Declaration classe Pressure
*/

#include <iostream>
#include "./Sensor.hpp"
#ifndef Pressure_h
#define Pressure_h

class Pressure : public Sensor<int>{

/***************CONSTRUCTORS***************/

//Default constructor
    public : Pressure();
//Constructor parametre
    public : Pressure(int);
//Constructor par recopie
    public : Pressure(const Pressure&);

/***************METHODS***************/
//gen random val
virtual void aleaGenVal();

/***************DESTRUCTOR***************/
virtual ~Pressure();

};

#endif