/**
 * @file Humidity.hpp
 * @author Aurélien PETRA
 * @brief Classe fille de "sensor", détermine et génère des valeurs d'humidité (entre 5 et 10)
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Define Guards
#ifndef HUMIDITY_H
#define HUMIDITY_H

#include <iostream>
#include "Sensor.hpp"

/**
 * @class humidity
 * @brief Classe fille de "sensor", détermine et génère des valeurs d'humidité (entre 5 et 10)
 */
class humidity : public sensor
{
public:
    humidity() {m_min = 5, m_max = 10;}
};

#endif //HUMIDITY_H