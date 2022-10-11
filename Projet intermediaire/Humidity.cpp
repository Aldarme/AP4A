/*!
 * @author  Cuenot Benoit  
 * @file    Humidity.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Humidity.cpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */
#include <iostream>
#include <string.h>
#include "Humidity.hpp"
#include <math.h>
#include <time.h>

using namespace std;

Humidity :: Humidity()
{
    m_donneeCapteur = 0;
}

Humidity :: ~Humidity()
{
   
}

Humidity :: Humidity(Humidity& ObjHumidity_p){

        m_donneeCapteur = ObjHumidity_p.m_donneeCapteur;
}

int Humidity :: aleaGenVal() /*!< On détermine ici l'humidité relative de l'air en % (qui varie normalement de 0 à 100%)*/
{
        srand(time(0));
        return rand()%+10+1; /*!< Etant à haute altitude, l'humidité est très basse avoisinant normalement les 0%. On considère alors des valeurs entre 0 et 10%*/
}