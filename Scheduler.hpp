#pragma once 
#include <iostream>
#include <cstdio>
#include "Sensor.hpp"
#include "Humidity.hpp"
#include "Temperature.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Server.hpp"


class Scheduler 
{
    private :
     
        Sensor* humidity;
        Sensor* temperature;
        Sensor* pression;
        Sensor* light;
        Server* server;
        int value_humidity;
        int value_temperature;
        int value_pression;
        int value_light;
        int seconds;
        void mySleep(int sleepMs);
        

    public :
        Scheduler();
        void start();
};

