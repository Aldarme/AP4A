/**
* @author MOhana wael
* @file : Scheduler.hpp
* @date 27/09/2022
* @Description Declaration classe Scheduler
*/

#include <iostream>
#include <fstream>
#include <string>
#include "./Server.hpp"
#include "./Sensor.hpp"
#include "./Temperature.hpp"
#include"./Light.hpp"
#include"./Pressure.hpp"
#include"./Humidity.hpp"

#ifndef Scheduler_h
#define Scheduler_h

class Scheduler{
    //params
    private : Server sv;
    private : Temperature t;
    private : Humidity h;
    private : Pressure p;
    private : Light l;

    /***************CONSTRUCTORS***************/
    public : Scheduler(){};

    /***************METHODS***************/
    public : void SignalServer();

};

#endif