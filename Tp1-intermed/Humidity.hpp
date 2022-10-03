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

class Humidity : public Sensor{

    public : Humidity():Sensor(){};
    
    public : Humidity(const Humidity& autre);

~Humidity();

};

#endif