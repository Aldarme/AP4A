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

#include "Sensor.hpp"

/**
 * @class light_
 * @brief Classe fille de "sensor", détermine et génère des valeurs de lumière (allumé ou éteint)
 */
class light_ : public sensor<bool, light_>
{
public:
    /**
     * @brief Génère un boolean aléatoire à partir de l'attribut m_data
     * 
     * @return light_& 
     */
    light_ &aleaGenVal();

    /**
     * @brief Initialise m_data avec un boolean aléatoire
     * 
     * @return light_& 
     */
    light_ &aleaInitVal();
};

#endif // LIGHT_H