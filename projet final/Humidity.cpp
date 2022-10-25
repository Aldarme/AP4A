#include "Humidity.hpp"
#include<stdlib.h>

float Humidity::aleaGenVal(float minValue, float maxValue)
{
    bool signe;
    data = 22;

    srand(time(0));
   
   data = data + (float)(rand()%50)/10;
  

    return data;
}

float dHumidity::getVal()
{
    float minValue = 20;
    float maxValue = 30;

    data = aleaGenVal(minValue, maxValue);
    return data;

}