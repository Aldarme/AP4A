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
    int minValue = 950;
    int maxValue = 1050;

    aleaGenVal(minValue, maxValue)
    {
        srand(time(0));
        return rand() % (maxValue - minValue) + minValue;
    }
}