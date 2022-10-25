/*!
 * @author  Cuenot Benoit  
 * @file    Humidity.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Humidity.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#ifndef HUMIDITY_HPP_INCLUDED
#define HUMIDITY_HPP_INCLUDED
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Sensor.hpp"
using namespace std;

template<typename T>
class Humidity : public Sensor<T>{
    
        private :

                virtual T aleaGenVal();
        
        public :
        
                Humidity(T = 0);
                ~Humidity();
                Humidity(Humidity& ObjHumidity_p);
};

template<typename T>
Humidity<T> :: Humidity(T donneecapteur_p)
{
        this->m_donneeCapteur = donneecapteur_p;
}

template<typename T>
Humidity<T> :: ~Humidity()
{
   
}

template<typename T>
Humidity<T> :: Humidity(Humidity& ObjHumidity_p){

        this->m_donneeCapteur = ObjHumidity_p.m_donneeCapteur;
}

template<typename T>
T Humidity<T> :: aleaGenVal() /*!< On détermine ici l'humidité relative de l'air en % (qui varie normalement de 0 à 100%)*/
{
        srand(time(0));
        float nbrAlea = rand()%+100+1;
        nbrAlea /= 10;
        return nbrAlea; /*!< Etant à haute altitude, l'humidité est très basse avoisinant normalement les 0 %. On considère alors des valeurs entre 0 et 10%*/
}

#endif // HUMIDITY_HPP_INCLUDED