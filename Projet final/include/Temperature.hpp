/*!
 * @author  Cuenot Benoit  
 * @file    Temperature.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Temperature.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#ifndef TEMPERATURE_HPP_INCLUDED
#define TEMPERATURE_HPP_INCLUDED
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Sensor.hpp"
using namespace std;

template<typename T>
class Temperature : public Sensor<T>{
      
        private : 

                virtual T aleaGenVal();
      
        public :
        
                Temperature(T = 0);
                ~Temperature();
                Temperature(const Temperature& objTemperature_p);        
};

template<typename T>
Temperature<T> :: Temperature(T donneecapteur_p)
{
        this->m_donneeCapteur = donneecapteur_p;
}

template<typename T>
Temperature<T> :: ~Temperature()
{
   
}

template<typename T>
Temperature<T> :: Temperature(const Temperature& objTemperature_p){

        this->m_donneeCapteur = objTemperature_p.m_donneeCapteur;
}

template<typename T>
T Temperature<T> :: aleaGenVal() /*!< On détermine ici la température à hautes altitudes */
{
        srand(time(0));
        float nbrAlea = rand()%(-400+600+1)-600;
        nbrAlea /= 10;
        return nbrAlea; /*!< On considère alors des valeurs entre -40 et -60 degrés */
}



#endif // TEMPERATURE_HPP_INCLUDED
