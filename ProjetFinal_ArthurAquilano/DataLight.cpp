/**
 * @author Arthur
 * @file DataLight.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Light
 */

#include "Data.hpp"
#include "Sensor.hpp"

bool DataLight::getVal()
{
    float minValue = 0;
    float maxValue = 2;

    aleaGenVal(minValue, maxValue)
    {
        srand(time(0));
        return rand() % (maxValue - minValue) + minValue;
    }
}