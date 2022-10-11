/*!
 * @author  Cuenot Benoit  
 * @file    Sensor.cpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Sensor.cpp. C'est la class Mère des différents capteurs où
 *          les attributs et méthodes vont pouvoir être instanciés. Les class Filles vont alors
 *          hériter des méthodes et attributs      
 */

#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>

#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"

using namespace std;

Sensor :: Sensor(int donneeCapteur_p)
{
        m_donneeCapteur = donneeCapteur_p;
}

Sensor :: ~Sensor()
{

}

Sensor :: Sensor(const Sensor& objSensor_p)
{
        m_donneeCapteur = objSensor_p.m_donneeCapteur;
}



int Sensor :: ValeurData() /*!< Permet uniquement de retourner la valeur de capteur, elle sera utile pour ensuite transmettre les données au Server*/
{
    return m_donneeCapteur;
}

int Sensor :: getData() /*!< La méthode getData() d'attribuer une valeurs aléatoire à m_donneeCapteur*/
{
    m_donneeCapteur = aleaGenVal(); 
    return m_donneeCapteur;  
}

