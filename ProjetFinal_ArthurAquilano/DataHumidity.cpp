/**
 * @author Arthur
 * @file DataHumidity.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Humidity
 */

#include "DataHumidity.hpp"

float DataHumidity::aleaGenVal(float minValue, float maxValue)
{
    bool signe;
    donnee = 30;

    srand(time(0));
    if (donnee <= minValue)
    {
        donnee = donnee + (float)(rand()%50)/10;
    } else if (donnee >= maxValue)
    {
        donnee = donnee - (float)(rand()%50)/10;
    } else 
    {
        signe = (bool)(rand()%(2));
        if(signe)
        {
            donnee = donnee + (float)(rand()%100)/50;
        } else 
        {
            donnee = donnee - (float)(rand()%100)/50;
        }
    }

    return donnee;
}

float DataHumidity::getVal()
{
    float minValue = 25;
    float maxValue = 40;

    donnee = aleaGenVal(minValue, maxValue);
    return donnee;

}