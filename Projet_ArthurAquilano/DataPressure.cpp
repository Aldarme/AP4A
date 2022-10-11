/**
 * @author Arthur
 * @file DataPressure.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Pressure
 */

#include "Data.hpp"
#include "Sensor.hpp"

int DataPressure::getVal()
{
    return aleaGenVal(90,110);
}