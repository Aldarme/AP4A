/**
 * @author Arthur
 * @file DataTemperature.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Température
 */

#include "DataTemperature.hpp"

float DataTemperature:: aleaGenVal(float minValue, float maxValue)
{
    bool signe;
    donnee = 20;

    srand(time(0));
    if (donnee <= minValue)
    {
        donnee = donnee + (float)(rand()%10)/10;
    } else if (donnee >= maxValue)
    {
        donnee = donnee - (float)(rand()%10)/10;
    } else 
    {
        signe = (bool)(rand()%(2));
        if(signe)
        {
            donnee = donnee + (float)(rand()%10)/10;
        } else 
        {
            donnee = donnee - (float)(rand()%10)/10;
        }
    }

    return donnee;
}


float DataTemperature::getVal()
{
   float minValue = 18;
   float maxValue = 24;

    donnee = aleaGenVal(minValue, maxValue);
    return donnee;

}