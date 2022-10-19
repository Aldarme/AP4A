/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file TemperatureSensor.hpp
 * @date 14/10/2022
 * @brief Définition de la class TemperatureSensor, spécifique à la température
 */

// Define guards
#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H

#include "Sensor.hpp"

/**
 * @class TemperatureSensor
 * @brief Sensor spécifique à la température
 * @brief Les données générées sont comprises entre 280K et 305K
 */
class TemperatureSensor : public Sensor<float>
{
public:
    //Forme canonique
    TemperatureSensor();
    virtual ~TemperatureSensor();
    TemperatureSensor(const TemperatureSensor& ts);
    TemperatureSensor& operator=(const TemperatureSensor& ts);
};

#endif // TEMPERATURESENSOR_H
