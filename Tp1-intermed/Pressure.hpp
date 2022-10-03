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

class Pressure : public Sensor{

    public : Pressure():Sensor(){};

    public : Pressure(const Pressure& autre);

~Pressure();

};

#endif