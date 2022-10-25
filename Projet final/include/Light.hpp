/*!
 * @author  Cuenot Benoit  
 * @file    Light.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Light.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */


#ifndef LIGHT_HPP_INCLUDED
#define LIGHT_HPP_INCLUDED
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>
#include "Sensor.hpp"
using namespace std;

template<typename T>
class Light : public Sensor<T>{
      
        private :  

                virtual T aleaGenVal();

        public :
        
                Light(T = 0);
                ~Light();
                Light(const Light& objLight_p);
};

template<typename T>
Light<T> :: Light(T donneecapteur_p)
{
        this->m_donneeCapteur = donneecapteur_p;
}

template<typename T>
Light<T> :: ~Light()
{
   
}

template<typename T>
Light<T> :: Light(const Light& objLight_p){

        this->m_donneeCapteur = objLight_p.m_donneeCapteur;
}

template<typename T>
T Light<T> :: aleaGenVal() /*!< On détermine ici la quantité de lumière en binaire */
{
        srand(time(0));
        return rand()%(+1-0+1)+0; /*!< 1 : il fait jour ; 0 : il fait nuit */
}





#endif // LIGHT_HPP_INCLUDED