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

#include "Sensor.hpp"

/**
 * @class pressure
 * @brief Classe fille de "sensor", détermine et génère des valeurs de pression
 */

class pressure : public sensor<int, pressure>
{
public:
    /**
     * @brief Génère un int aléatoire compris entre 75 et 81 à partir de l'attribut m_data
     * 
     * @return pressure& 
     */
    pressure &aleaGenVal();

    /**
     * @brief Initialise m_data avec un int aléatoire compris entre 75 et 81
     * 
     * @return pressure& 
     */
    pressure &aleaInitVal();
};

#endif // PRESSURE_H