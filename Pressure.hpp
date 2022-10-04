/**
* @author laduguie
* @file Pressure . hpp
* @date 28/09/2022
* @brief Pressure captor for the plane
*/

// Define  guards
#ifndef PRESSURE_H
#define PRESSURE_H


#include "Sensor.hpp"

class Pressure : public Sensor //lien d'hérédité
{
    private:
     
    public:
        Pressure(); //constructeur par défaut
        Pressure(const Pressure&); //constructeur par recopie
        Pressure &operator=(const Pressure&); //operateur d'afffectation
        ~Pressure(); //Destructeur

};

#endif //Pressure
