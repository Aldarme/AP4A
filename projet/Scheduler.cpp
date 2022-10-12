/**
 * @author lois roger
 * @file Sensor.hpp
 * @date 05/10/2022
 * @brief  recupère les données des capteurs toutes les 5 secondes et les envoient au server
 */

#include "Scheduler.hpp"
#include "Server.hpp"
#include <iostream>
#include <unistd.h>


void Scheduler::attendre()
{
    int i = 0;
    while(i<5)
    {
        int valeurt = m_temperature.getData(15,40);
        int valeurh = m_humidity.getData(0, 100);
        int valeurp = m_pression.getData(1000, 100);
        int valeurl = m_light.getData(0, 1);
        
        m_serv.consolwrite(valeurt, valeurh, valeurl, valeurp);
        m_serv.filewrite(valeurt, valeurp, valeurl, valeurh);
        sleep(5);
        i = i+1;
    }
}