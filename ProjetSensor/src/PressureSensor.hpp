/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file PressureSensor.hpp
 * @date 14/10/2022
 * @brief Définition de la class PressureSensor, spécifique à la pression
 */

// Define guards
#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include "Sensor.hpp"

/**
 * @class PressureSensor
 * @brief Sensor spécifique à la pression atmosphérique
 * @brief Les données générées sont comprises entre 100 hPa et 1014 hPa
 */
class PressureSensor : public Sensor<int>
{
public:
    //Forme canonique
    PressureSensor();
    virtual ~PressureSensor();
    PressureSensor(const PressureSensor& ps);
    PressureSensor& operator=(const PressureSensor& ps);
};

#endif // PRESSURESENSOR_H
