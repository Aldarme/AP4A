/**
 * @author  gilles_maurer
 * @file    Scheduler.hpp
 * @date    03/10/2022
 * @brief   Scheduler class, manage the sensors and the server, use the clock to regulate
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Server.hpp"
#include "Sensor.hpp"

#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Temperature.hpp"

class Scheduler
{
private:
    Sensor* m_pHu;
    Sensor* m_pTe; 
    Sensor* m_pPr;
    Sensor* m_pLi; 
    
public:
    //Definition of the canonical form
    Scheduler();
    Scheduler(const Scheduler& param_sc);
    Scheduler& operator=(const Scheduler& param_sc);
    ~Scheduler();

    //manage all the simulation
    void scheduler();   
};

//wait param_time seconds
void clock(int param_time);

//ask the user if he want to activate the console and the logs
void initilizeServerParameters(Server& param_server);

#endif // SCHEDULER_H