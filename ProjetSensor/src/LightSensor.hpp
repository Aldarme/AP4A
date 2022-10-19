/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file LightSensor.hpp
 * @date 14/10/2022
 * @brief Définition de la class LightSensor, spécifique à la lumière
 */

// Define guards
#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "Sensor.hpp"

/**
 * @class LightSensor
 * @brief Sensor spécifique à la lumière
 * @brief Les données générées sont 1 si la lumière est allumée, sinon 0
 */
class LightSensor : public Sensor<bool>
{
public:
    //Forme canonique
    LightSensor();
    virtual ~LightSensor();
    LightSensor(const LightSensor& ls);
    LightSensor& operator=(const LightSensor& ls);
};

#endif // LIGHTSENSOR_H
