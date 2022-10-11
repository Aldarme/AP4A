/**
 * @file Light.hpp
 * @author Aurélien PETRA
 * @brief Classe fille de "sensor", détermine et génère des valeurs de lumière (0 ou 1)
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

// Define guards
#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>
#include "Sensor.hpp"

/**
 * @class light_
 * @brief Classe fille de "sensor", détermine et génère des valeurs de lumière (allumé ou éteint)
 */
class light_ : public sensor
{
public:
    light_() { m_min = 0, m_max = 1; }
};

#endif // LIGHT_H