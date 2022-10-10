/**
 * @author RENON Emilien
 * @file Light.hpp
 * @date 04/10/2022
 * @brief La classe Light permettra de caractèriser un capteur de lumière.
 */

//
// Define guards
#ifndef LIGHT_H
#define LIGHT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Sensor.hpp"

/**
 * @class Light
 * @brief La classe Light simule le fonctionnement du capteur de lumière
 */
template <class T>
class Light : public Sensor<bool>
{
public:
    // Definition de la forme canonique
    Light();
    Light(const Light &param_light);
    ~Light(){};
    // ...
      
};


#endif // LUMIERE_H