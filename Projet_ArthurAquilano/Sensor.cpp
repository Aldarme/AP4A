/**
 * @author Arthur
 * @file Sensor.hpp
 * @date 03/10/22
 * @brief Implémentation de la classe Sensor
 */

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

int Sensor:: aleaGenVal(int minValue, int maxValue)
{
    srand(time(0));
    return rand() % (maxValue - minValue) + minValue;
}