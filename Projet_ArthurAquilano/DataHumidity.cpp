/**
 * @author Arthur
 * @file DataHumidity.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Humidity
 */

#include "Data.hpp"
#include "Sensor.hpp"

int DataHumidity::getVal()
{
    return aleaGenVal(20,40);
}