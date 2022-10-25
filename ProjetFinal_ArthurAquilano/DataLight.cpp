/**
 * @author Arthur
 * @file DataLight.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Light
 */

#include "DataLight.hpp"

bool DataLight::aleaGenVal(bool minValue, bool maxValue)
{
    donnee = true;

    srand(time(0));
    donnee = (bool)(rand()%(2));

    return donnee;
}

bool DataLight::getVal()
{
    bool minValue = 0;
    bool maxValue = 1;

    donnee = aleaGenVal(minValue, maxValue);
    return donnee;

}