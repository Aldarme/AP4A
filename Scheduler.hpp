#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <iostream>
#include <cstdio>
#include "Sensor.hpp"
#include "Humidity.hpp"
#include "Temperature.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Server.hpp"


typedef struct CaptorValues //struct qui comporte les valeurs des capteurs 
{
    float value_humidity;
    float value_temperature;
    int value_pression;
    bool value_light;
}CaptorValues;

class Scheduler 
{
    private :
        Sensor<float>* humidity;
        Sensor<float>* temperature;
        Sensor<int>* pression;
        Sensor<bool>* light;
        Server* server;
        int seconds;
        CaptorValues captor_values;
        void mySleep(int sleepMs);

    public :
        Scheduler();
        void start();
};

#endif