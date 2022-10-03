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

class Temperature : public Sensor{

    public : Temperature():Sensor(){};

    public : Temperature(const Temperature& autre);

~Temperature();

};

#endif