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

    Temperature m_temp;
    Humidity m_humi;
    Light m_lig;
    Pression m_pres;
    Server m_serv;

    public :

    Scheduler();

    Scheduler(const Scheduler& s);

    ~Scheduler();

    void sendData();

};

#endif // Projet_AP4A_SCHEDULER_H