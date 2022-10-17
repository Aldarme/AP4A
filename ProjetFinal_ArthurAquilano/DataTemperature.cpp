/**
 * @author Arthur
 * @file DataTemperature.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Température
 */

#include "Data.hpp"
#include "Sensor.hpp"

float DataTemperature::getVal()
{
   float minValue = 18;
   float maxValue = 24;

    aleaGenVal(minValue, maxValue)
    {
        srand(time(0));
        return rand() % (maxValue - minValue) + minValue;
    }
}