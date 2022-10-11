/**
 * @author Arthur
 * @file DataTemperature.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Température
 */

#include "Data.hpp"
#include "Sensor.hpp"

int DataTemperature::getVal()
{
    return aleaGenVal(15,25);
}