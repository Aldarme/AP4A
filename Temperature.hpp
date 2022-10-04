/**
* @author laduguie
* @file Temperature . hpp
* @date 28/09/2022
* @brief Temperature captor for the plane
*/

// Define  guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H


#include "Sensor.hpp"

class Temperature : public Sensor
{
    private:
    
    public:
        Temperature(); //constructeur par défaut
        Temperature(const Temperature&); //constructeur par recopie
        Temperature &operator=(const Temperature&); //operateur d'afffectation
        ~Temperature(); //Destructeur

};

#endif //TEMPERATURE
