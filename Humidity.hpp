/**
* @author laduguie
* @file Humidity . hpp
* @date 28/09/2022
* @brief Définition de la classe Humidity
*/

// Define  guards
#ifndef HUMIDITY_H
#define HUMIDITY_H


#include "Sensor.hpp"

class Humidity : public Sensor<float> //on créé la classe Humidity
{
    private:
        float aleaGenVal(){
            return m_min + static_cast<float>(rand()) * static_cast<float>(m_max - m_min) / RAND_MAX; //random pour un float
        }
    public:
        Humidity()
        {
            m_min = 0;        
            m_max = 100;
        }; //constructeur par défaut
        Humidity(const Humidity&); //constructeur par recopie
        Humidity &operator=(const Humidity&); //operateur d'afffectation
        ~Humidity(){}; //Destructeur

};

#endif //HUMIDITY
