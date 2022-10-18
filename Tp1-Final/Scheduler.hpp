/**
* @author MOhana wael
* @file : Scheduler.hpp
* @date 27/09/2022
* @Description Declaration classe Scheduler
*/

#include <iostream>
#include <fstream>
#include <string>
#include "./Server.cpp"
#include "./Sensor.hpp"
#include "./Temperature.cpp"
#include"./Light.cpp"
#include"./Pressure.cpp"
#include"./Humidity.cpp"

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
    //Default constructor
    public : Scheduler();
    //Constructor par recopie
    public : Scheduler(const Scheduler&);

    /***************METHODS***************/ 
    public :void SignalServer();
    private : void Temperature_thread_func();
    void Light_thread_func();

    /***************DESTRUCTOR***************/
public : virtual ~Scheduler();

};

#endif