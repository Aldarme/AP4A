/*!
 * @author  Cuenot Benoit  
 * @file    Pression.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Pression.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfinie.              
 */

#ifndef PRESSION_HPP_INCLUDED
#define PRESSION_HPP_INCLUDED
#include "Sensor.hpp"
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;

template<typename T>
class Pression : public Sensor<T>{
      
        private : 

                T aleaGenVal();
                            
        public :

                Pression(T = 0);
                ~Pression();
                Pression(const Pression& objPression_p);
};

template<typename T>
Pression<T> :: Pression(T donneecapteur_p)
{
       this-> m_donneeCapteur = donneecapteur_p;
}

template<typename T>
Pression<T> :: ~Pression()
{
   
}

template<typename T>
Pression<T> :: Pression(const Pression& objPression_p){

        this-> m_donneeCapteur = objPression_p.m_donneeCapteur;
}

template<typename T>
T Pression<T> :: aleaGenVal() /*!< On détermine ici la pression >*/
{
        srand(time(0));
        return rand()%(+350-200+1)+200; /*!< Entre 8000 et 11 000 mètres d'altitude, on considère que le pression varie de 200 à 350 hPa */
}


#endif // PRESSION_HPP_INCLUDED