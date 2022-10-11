/*!
 * @author  Cuenot Benoit  
 * @file    Temperature.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Temperature.cpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#include <iostream>
#include <string.h>
#include "Temperature.hpp"
#include <math.h>
#include <time.h>

using namespace std;

Temperature :: Temperature()
{
        m_donneeCapteur = 0;
}

Temperature :: ~Temperature()
{
   
}

Temperature :: Temperature(const Temperature& objTemperature_p){

        m_donneeCapteur = objTemperature_p.m_donneeCapteur;
}

int Temperature :: aleaGenVal() /*!< On détermine ici la température à hautes altitudes */
{
        srand(time(0));
        return rand()%(-40+60+1)-60; /*!< On considère alors des valeurs entre -40 et -60 degrés */
}
