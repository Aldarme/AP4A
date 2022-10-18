/**
* @author laduguie
* @file Temperature . hpp
* @date 28/09/2022
* @brief Définition de la classe Temperature
*/

// Define  guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H


#include "Sensor.hpp"

class Temperature : public Sensor<float> //la classe temperature hérite de sensor 
{
    private:
        float aleaGenVal()
        {
            return m_min + static_cast<float>(rand()) * static_cast<float>(m_max - m_min) / RAND_MAX; //random pour un float
        };
    public:
        Temperature()
        {
            m_min = 20;
            m_max = 30;
        }; //constructeur par défaut
        Temperature(const Temperature&); //constructeur par recopie
        Temperature &operator=(const Temperature&); //operateur d'afffectation
        ~Temperature(){}; //Destructeur

};

#endif 
