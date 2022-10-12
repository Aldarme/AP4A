/**
* @author Alan HERVE
* @file Scheduler.hpp
* @date 01/10/2022
* @brief Is in charge of getting values from our captors and sending them to the Server class
**/



#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>


#include "Temperature.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Humidity.hpp"
#include "Server.hpp"




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
        int step;
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


        Scheduler() :
        frequency(10),
        step(0),
        going(true)
        {
            
            std::cout << "Press 'c' to manage console activation, an 'l' for log activation" << std::endl;
            this->startClock();    
        }


        Scheduler(const Scheduler& copy)
        {
            this->frequency = copy.frequency;
        }

        virtual ~Scheduler()
        {

        }

        void startClock();

        



};

#endif