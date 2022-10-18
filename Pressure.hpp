/**
* @author laduguie
* @file Pressure . hpp
* @date 28/09/2022
* @brief Définitionde la classe Pressure
*/

// Define  guards
#ifndef PRESSURE_H
#define PRESSURE_H


#include "Sensor.hpp"

class Pressure : public Sensor<int> //lien d'hérédité
{
    private:
        int aleaGenVal() 
        {
            return (rand()%(m_max-m_min))+m_min;
        };
    public:
        Pressure()
        {    
            m_min = 900;
            m_max = 1100;
        }; //constructeur par défaut
        Pressure(const Pressure&); //constructeur par recopie
        Pressure &operator=(const Pressure&); //operateur d'afffectation
        ~Pressure(){}; //Destructeur

};

#endif //Pressure
