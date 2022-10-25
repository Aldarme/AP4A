/**
 * @author Arthur
 * @file DataPressure.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Pressure
 */

#include "DataPressure.hpp"

int DataPressure::aleaGenVal(int minValue, int maxValue)
{
    bool signe;
    donnee = 100;

        srand(time(0));
    if (donnee <= minValue)
    {
        donnee = donnee + (rand()%3);
    } else if (donnee >= maxValue)
    {
        donnee = donnee - (rand()%3);
    } else 
    {
        signe = (bool)(rand()%(2));
        if(signe)
        {
            donnee = donnee + (rand()%3);
        } else 
        {
            donnee = donnee - (rand()%3);
        }
    }
    
    return donnee;
}


int DataPressure::getVal()
{
    int minValue = 95;
    int maxValue = 105;

    donnee = aleaGenVal(minValue, maxValue);
    return donnee;

}