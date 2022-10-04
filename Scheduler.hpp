/**
* @author laduguie
* @file Scheduler.hpp
* @date 28/09/2022
* @brief The scheduler takes the data to send it to the server every second
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Humidity.hpp"
#include "Light.hpp"
#include "Pressure.hpp"
#include "Temperature.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

class Scheduler
{
    private:
        Sensor* captorHumidity;
        Sensor* captorLight;
        Sensor* captorPressure;
        Sensor* captorTemp;
        Server objetServer;
    public:
        Scheduler() //constructeur par defaut
        {
            captorHumidity = new Humidity();
            captorLight = new Light();
            captorPressure = new Pressure();
            captorTemp = new Temperature();
        }
        Scheduler(const Scheduler&); //constructeur par recopie
        Scheduler &operator=(const Scheduler&); //operateur d'afffectation
        ~Scheduler(){} //Destructeur
        
        void run();

};

#endif
