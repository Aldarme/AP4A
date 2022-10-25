/*!
 * @author  Cuenot Benoit  
 * @file    Sensor.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Sensor.hpp. C'est la class Mère des différents capteurs où
 *          les attributs et méthodes vont pouvoir être instanciés. Les class Filles vont alors
 *          hériter des méthodes et attributs.
 *          On considère ici un avion étant entre 8000 mètres et 11 000 mètres d'altitudes pour les données de capteurs.      
 */
#ifndef SENSOR_HPP_INCLUDED
#define SENSOR_HPP_INCLUDED
#include <iostream>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;

template<typename T>
class Sensor{   /*!< La classe Sensor est considéré comme une classe abstraite car cela n'a pas de sens de créer une classe Sensor sans spécifier quel type de capteur*/
  
        protected : /*!< Ces données sont mis en protected pour que les class filles puissent hériter*/

                T m_donneeCapteur;
                virtual T aleaGenVal() = 0; /*!< Le mot virtual est placé devant cette fonction car elle sera redéfinie pour chaque capteur.*/
      
        public :
        
                Sensor(T = 0);
                Sensor(const Sensor& objSensor_p);
                ~Sensor();
                virtual T getData(); /*!< La méthode getData() d'attribuer une valeurs aléatoire à m_donneeCapteur*/
};

template<typename T>
Sensor<T> :: Sensor(T donneeCapteur_p)
{
        m_donneeCapteur = donneeCapteur_p;
}

template<typename T>
Sensor<T> :: ~Sensor()
{

}

template<typename T>
Sensor<T> :: Sensor(const Sensor& objSensor_p)
{
        m_donneeCapteur = objSensor_p.m_donneeCapteur;
}

template<typename T>
T Sensor<T> :: getData() /*!< La méthode getData() d'attribuer une valeurs aléatoire à m_donneeCapteur*/
{
        m_donneeCapteur = aleaGenVal(); 
        return m_donneeCapteur;  
}

#endif // SENSOR_HPP_INCLUDED