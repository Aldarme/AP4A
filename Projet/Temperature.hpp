/**
 * @file Temperature.hpp
 * @author Aurélien PETRA
 * @brief Classe fille de "sensor", détermine et génère des valeurs de température (entre 20 et 25)
 * @version 0.1
 * @date 2022-10-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include "Sensor.hpp"

/**
 * @class temperture
 * @brief Classe fille de "sensor", détermine et génère des valeurs de température
 */
class temperature : public sensor
{
public:
    temperature() {m_min = 20, m_max = 25;}
};

#endif // TEMPERATURE_H