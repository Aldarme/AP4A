/**
 * @file Pressure.hpp
 * @author Aurélien PETRA
 * @brief Classe fille de "sensor", détermine et génère des valeurs de pression (entre 75 et 81)
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef PRESSURE_H
#define PRESSURE_H

#include <iostream>
#include "Sensor.hpp"

/**
 * @class pressure
 * @brief Classe fille de "sensor", détermine et génère des valeurs de pression
 */
class pressure : public sensor
{
public:
    pressure() { m_min = 75, m_max = 81; }
};

#endif // PRESSURE_H