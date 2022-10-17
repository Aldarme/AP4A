/**
 * @author Arthur
 * @file DataHumidity.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Humidity
 */

#include "Data.hpp"
#include "Sensor.hpp"

float DataHumidity::getVal()
{
    float minValue = 25;
    float maxValue = 40;

    aleaGenVal(minValue, maxValue)
    {
        srand(time(0));
        return rand() % (maxValue - minValue) + minValue;
    }
}