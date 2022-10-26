#ifndef SCHEDULER_H
#define SCHEDULER_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Scheduler
*/

#include "Server.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Humidity.hpp"

class Scheduler
{
private:
    Light m_light;
    Temperature m_temp;
    Pressure m_pres;
    Humidity m_humid;

    void sendData(Server p_server);

public:
    Scheduler();
};
#endif // SCHEDULER_H