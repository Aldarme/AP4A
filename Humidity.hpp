/**
* @author laduguie
* @file Humidity . hpp
* @date 28/09/2022
* @brief Humidity captor for the plane
*/

// Define  guards
#ifndef HUMIDITY_H
#define HUMIDITY_H


#include "Sensor.hpp"

class Humidity : public Sensor //on créé la classe Humidity
{
    private:
    
    public:
        Humidity(); //constructeur par défaut
        Humidity(const Humidity&); //constructeur par recopie
        Humidity &operator=(const Humidity&); //operateur d'afffectation
        ~Humidity(); //Destructeur

};

#endif //HUMIDITY
