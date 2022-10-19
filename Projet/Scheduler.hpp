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

        

        int m_frequency;
        int m_step;
        bool m_going;
        

       //objects we used to generate values
        Temperature m_temperatureObject;
        Light m_lightObject;
        Humidity m_humidtyObject;
        Pression m_pressionObject;
        Server m_serverObject;

        //structures we use to send data to server
        humidity_data m_humidity_d;
        pression_data m_pression_d;
        light_data m_light_d;
        temperature_data m_temperature_d;

       
    public:


        Scheduler() :
        m_frequency(10),
        m_step(0),
        m_going(true)
        {
            
            std::cout << "Press 'c' to manage console activation, an 'l' for log activation" << std::endl;
            this->startClock();    
        }


        Scheduler(const Scheduler& p_copy) :
        m_frequency(p_copy.m_frequency),
        m_step(p_copy.m_step),
        m_going(p_copy.m_going)
        {
            
        }

        virtual ~Scheduler()
        {

        }

        void startClock();

        



};

#endif