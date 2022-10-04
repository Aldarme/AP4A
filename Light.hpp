/**
* @author laduguie
* @file Light.hpp
* @date 28/09/2022
* @brief Light captor for the plane
*/

// Define  guards
#ifndef LIGHT_H
#define LIGHT_H


#include "Sensor.hpp"

class Light : public Sensor
{
    private:

    public:
        Light(); //constructeur par défaut
        Light(const Light&); //constructeur par recopie
        Light &operator=(const Light&); //operateur d'afffectation
        ~Light(); //Destructeur

};

#endif //LIGHT
