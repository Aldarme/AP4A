/**
 * @author DURUPT Corentin
 * @file Scheduler.hpp
 * @date 23/09/2022
 * @brief this header is composed of the class Scheduler
*/

#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include<iostream>
#include"Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pressure.hpp"

/**
 * @class Scheduler
 * @brief this class allows to create a Scheduler. It means to define a frequency in order to generate datas of each Sensor and sendind them into the Server
*/
class Scheduler
{
public:
    int m_frequency_t; //the frequency of the scheduler for Temperature
    int m_frequency_h; //the frequency of the scheduler for Humidity
    int m_frequency_l; //the frequency of the scheduler for Light
    int m_frequency_p; //the frequency of the scheduler for Pressure

public:
    /**
    *@brief the default constructor 
    */
    Scheduler();
    /**
    *@brief the destructor 
    */
    ~Scheduler();
    /**
    *@brief this constructor initialize the frequency of the scheduler
    *@param freq => the frequency of the scheduler
    */
    Scheduler(int freq_t, int freq_h, int freq_l, int freq_p);
    /**
    *@brief this method allows to Sensors to generate theirs datas at a certain frequency and sends it into the Server.
    *@param t => a Temperature's Sensor 
    *@param h => a Humidity's Sensor
    *@param l => a Light's Sensor
    *@param p => a Pressure's Sensor
    */
    void timer(Temperature& t, Humidity& h, Light& l, Pressure& p);

    friend class Server;
};


#endif // _SCHEDULER_H