/**
 * @author YUHUIFEI
 * @file SCHEDULER.h
 * @date 15/10/2022
 * @brief R¨¦cup¨¦ration des donn¨¦es dans des threads s¨¦par¨¦s et envoi au serveur
 */
#ifndef SCHEDULER_H
#define SCHEDULER_H


#include <iostream>
#include "TEMPERATURE.cpp"
#include "PRESSION.cpp"
#include "LIGHT.cpp"
#include "HUMIDITY.cpp"
#include "SENSOR.h"
#include "SERVER.h"

using namespace std;

class Scheduler
{
public:
    Scheduler() {};
    Scheduler(const Server& param_server, const Temperature& param_temperature, const Humidity& param_humidity, const Light& param_light, const Pression& param_pression);
    Scheduler(const Scheduler& s);
    ~Scheduler() {};
    void total_tem();
    void total_hum();
    void total_pre();
    void total_lig();
    void sendServer(int param_actual_time, int param_time_temperature, int param_time_pression, int param_time_light, int param_time_humidity);
    friend class Server;
    friend class Temperature;
    friend class Humidity;
    friend class Light;
    friend class Pression;
    template <class T> class Sensor;
    Temperature m_temperature;
    Humidity m_humidity;
    Light m_light;
    Pression m_pression;
    Server m_server;
};

#endif//SCHEDULER.H
