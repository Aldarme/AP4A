/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file HumiditySensor.hpp
 * @date 14/10/2022
 * @brief Définition de la class HumiditySensor, sépcifique à l'humidité
 */

// Define guards
#ifndef HUMIDITYSENSOR_H
#define HUMIDITYSENSOR_H

#include "Sensor.hpp"

/**
 * @class HumiditySensor
 * @brief Sensor spécifique à l'humidité
 * @brief Les données générées sont comprises entre 5% et 30% d'humidité
 */
class HumiditySensor : public Sensor<float>
{
public:
    //Forme canonique
    HumiditySensor();
    virtual ~HumiditySensor();
    HumiditySensor(const HumiditySensor& hs);
    HumiditySensor& operator=(const HumiditySensor& hs);
};

#endif // HUMIDITYSENSOR_H
