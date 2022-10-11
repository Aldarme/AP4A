/*!
 * @author  Cuenot Benoit  
 * @file    Pression.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Pression.cpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#include <iostream>
#include <string.h>
#include "Pression.hpp"
#include <math.h>
#include <time.h>

using namespace std;

Pression :: Pression()
{
        m_donneeCapteur = 0;
}

Pression :: ~Pression()
{
   
}

Pression :: Pression(const Pression& objPression_p){

        m_donneeCapteur = objPression_p.m_donneeCapteur;
}

int Pression :: aleaGenVal() /*!< On détermine ici la quantité de lumière en Lux qu'envoie le soleil (entre 0 et 120 000 lux) */
{
        srand(time(0));
        return rand()%(+350-200+1)+200; /*!< Entre 8000 et 11 000 mètres d'altitude, on considère que le pression varie de 200 à 350 hPa */
}