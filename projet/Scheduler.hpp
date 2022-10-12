/**
 * @author lois ROGER
 * @file Scheduleur.hpp
 * @date 05/09/2022
 * @brief recupère les données des capteurs toutes les 5 secondes et les envoient au server
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Server.hpp" 
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Sensor.hpp"

class Scheduler
{
    public:
        Server m_serv;
        Humidity m_humidity;
        Light m_light;
        Temperature m_temperature;
        Pression m_pression;
        Scheduler();
        void attendre();
        

};



#endif