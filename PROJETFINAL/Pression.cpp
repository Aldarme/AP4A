#include "Pression.hpp"

int Pressure::aleaGenVal(int minValue, int maxValue)
{
    
    data = 100;

        srand(time(0));
   
        data = data - (rand()%3);
        data = data + (rand()%3);
   
    
    return data;
}

int DataPressure::getVal()
{
    int minValue = 90;
    int maxValue = 110;

    donnee = aleaGenVal(minValue, maxValue);
    return data;
