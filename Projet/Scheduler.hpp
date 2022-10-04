/**
* @author Alan HERVE
* @file Scheduler.hpp
* @date 01/10/2022
* @brief Is in charge of getting values from our captors and sending them to the Server class
**/



#ifndef SCHEDULER_H
#define SCHEDULER_H

#pragma once

#include <iostream>
#include <chrono>
#include <thread>

#include "Temperature.cpp"
#include "Pression.cpp"
#include "Light.cpp"
#include "Humidity.cpp"
#include "Server.cpp"



struct humidity_data
{
    float info;
    const int type = 0;
};

struct temperature_data
{
    float info;
    const int type = 3;
};

struct light_data
{
    bool info;
    const int type = 1;
};

struct pression_data
{
    int info;
    const int type = 2;
};


class Scheduler
{
    private:

        

        int frequency;
        bool going;

       
        Temperature temperature_object;
        Light light_object;
        Humidity humidty_object;
        Pression pression_object;
        Server server_object;

        humidity_data humidity_d;
        pression_data pression_d;
        light_data light_d;
        temperature_data temperature_d;

       
    public:


        Scheduler()
        {
            this->frequency = 5;
            this->going = true;

            this->startClock();    
        }


        Scheduler(const Scheduler& copy)
        {
            this->frequency = copy.frequency;
        }

        ~Scheduler()
        {

        }

        void startClock();

        



};

#endif