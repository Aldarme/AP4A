/**
* @author MOhana wael
* @file : Sensor.hpp
* @date 27/09/2022
* @Description Declaration classe Sensor
*/

#include <iostream>
#ifndef Sensor_h
#define Sensor_h

class Sensor{
//params
    protected :  int val;


//Default constructor
    public : Sensor();
//Clone Constructor
    Sensor(const Sensor&);

    Sensor& operator=(const Sensor& autre);

//gen random val
    private : void aleaGenVal();
//Get Data
    public : int getData();

~Sensor();

};

#endif