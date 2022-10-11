/*!
 * @author  Cuenot Benoit  
 * @file    Light.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Light.cpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#include <iostream>
#include <string.h>
#include "Light.hpp"
#include <math.h>
#include <time.h>

using namespace std;

Light :: Light()
{
        m_donneeCapteur = 0;
}

Light :: ~Light()
{
   
}

Light :: Light(const Light& objLight_p){

        m_donneeCapteur = objLight_p.m_donneeCapteur;
}

int Light :: aleaGenVal() /*!< On détermine ici la quantité de lumière en Lux qu'envoie le soleil (entre 0 et 120 000 lux) */
{
        srand(time(0));
        return rand()%(+120000-115000)+115000; /*!< On considère être en pleine journée dans un situation où les rayons du soleil sont perpendiculaires à l'avion avec des valeurs variant entre 115 000 et 120 000 Lux */
}