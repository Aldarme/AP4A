/**
* @author laduguie
* @file Light.hpp
* @date 28/09/2022
* @brief Définition de la classe Light
*/

// Define  guards
#ifndef LIGHT_H
#define LIGHT_H


#include "Sensor.hpp"

class Light : public Sensor<bool>
{
    private:
        bool aleaGenVal()
        {
            return rand()%2==0?false:true; //random pour un bool
        }

    public:
        Light() 
        {
            m_min = false;
            m_max = true;
        };//constructeur par défaut
        Light(const Light&); //constructeur par recopie
        Light &operator=(const Light&); //operateur d'afffectation
        ~Light(){}; //Destructeur

};

#endif //LIGHT
