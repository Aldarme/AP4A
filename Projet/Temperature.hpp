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

#include "Sensor.hpp"

/**
 * @class temperture
 * @brief Classe fille de "sensor", détermine et génère des valeurs de température
 */
class temperature : public sensor<float, temperature>
{
public:
    /**
     * @brief Génère un float aléatoire compris entre 20 et 25 à partir de l'attribut m_data
     * 
     * @return temperature& 
     */
    temperature &aleaGenVal();

    /**
     * @brief Initialise m_data avec un float aléatoire compris entre 20 et 25
     * 
     * @return temperature& 
     */
    temperature &aleaInitVal();
};

#endif // TEMPERATURE_H