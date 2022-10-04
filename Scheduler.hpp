/**
 * @author DURUPT Corentin
 * @file Scheduler.hpp
 * @date 23/09/2022
 * @brief this header is composed of the class Scheduler
*/

#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include<iostream>
#include"Sensor.hpp"
#include"Server.hpp"

/**
 * @class Scheduler
 * @brief this class allows to create a Scheduler. It means to define a frequency in order to generate datas of each Sensor and sendind them into the Server
*/
class Scheduler
{
private :
    int m_frequency; //the frequency of the scheduler

public :
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
    Scheduler(int freq);
    /**
    *@brief this method allows to Sensors to generate theirs datas at a certain frequency and sends it into the Server.
    *@return a Server
    *@param t => a Temperature's Sensor 
    *@param h => a Humidity's Sensor
    *@param l => a Light's Sensor
    *@param p => a Pressure's Sensor
    */
    Server timer(Temperature& t, Humidity& h, Light& l, Pressure& p);
};


#endif // _SCHEDULER_H