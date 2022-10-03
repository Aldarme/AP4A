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

class Light : public Sensor{

    public : Light():Sensor(){};

    public : Light(const Light& autre);

~Light();

};


#endif