/*
* @author Metral Greg
* @file Scheduler.hpp
* @date 17/10/2022
* @brief toute les secondes, va prender une ou plusieurs donnée et appeler le server pour les print
*/


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
        Sensor<float>* pHumidity;
        Sensor<float>* pTemperature;
        Sensor<int>* pPression;
        Sensor<bool>* pLight;
        Server* pServer;
        int m_seconds;
        CaptorValues s_captor_values;
        void mySleep(int sleepMs_p);

    public :
        friend class Server;
        Scheduler();
        ~Scheduler()
        {
            delete(pHumidity);
            delete(pTemperature);
            delete(pPression);
            delete(pLight);
            delete(pServer);
        };
        void start();

};

#endif