/**
 * @author choulot_hugo
 * @file Scheduler.hpp
 * @date 23/09/2022
 * @brief Cette classe permet de gérer les flux de données envoyé par les capteurs
 */

//
// Define guards
#ifndef Projet_AP4A_SCHEDULER_H
#define Projet_AP4A_SCHEDULER_H

#include "Sensor.hpp"
#include "Server.hpp"

class Scheduler{

    private :

    int m_temperature_scheduler;
    int m_humidity_scheduler;
    int m_light_scheduler;
    int m_pression_scheduler;

    public :

    Scheduler();

    Scheduler(const Scheduler& s);

    ~Scheduler();

    void sendData(Temperature& t, Humidity& h, Light& l, Pression& p, Server& s);

    int getTemperature();

    int getHumidity();

    int getLight();

    int getPression();

    void setData(Temperature& t, Humidity& h, Light& l, Pression& p);
};

#endif // Projet_AP4A_SCHEDULER_H