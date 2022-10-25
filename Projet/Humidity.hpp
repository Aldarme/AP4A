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

#include "Sensor.hpp"

/**
 * @class humidity
 * @brief Classe fille de "sensor", détermine et génère des valeurs d'humidité (entre 5 et 10)
 */
class humidity : public sensor<float, humidity>
{
public:
    /**
     * @brief Génère un float aléatoire compris entre 5 et 10 à partir de l'attribut m_data
     * 
     * @return humidity& 
     */
    humidity &aleaGenVal();

    /**
     * @brief Initialise m_data avec un float aléatoire compris entre 5 et 10
     * 
     * @return humidity& 
     */
    humidity &aleaInitVal();
};

#endif // HUMIDITY_H