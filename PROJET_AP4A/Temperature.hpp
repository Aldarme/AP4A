/**
 * @author RENON Emilien
 * @file Teperature.hpp
 * @date 04/10/2022
 * @brief La classe Temperature permettra de caractèriser un capteur de température.
 */

//
// Define guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Sensor.hpp"

/**
 * @class Temperature
 * @brief La classe Temperature simule le fonctionnement du capteur de température
 */
template <class T>
class Temperature : public Sensor<float>
{
public:
    // Definition de la forme canonique
    Temperature();
    Temperature(const Temperature &param_temperature);
    ~Temperature(){};
    // ...
       
};
#endif // TEMPERATURE_H