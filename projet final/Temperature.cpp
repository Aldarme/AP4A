#include "Temperature.hpp"
#include <iostream> 

float Temperature:: aleaGenVal(float minValue, float maxValue)
{
    data = 22;
    srand(time(0));
    
        {
            data = data + (float)(rand()%10)/10;
       
            data = data - (float)(rand()%10)/10;
    
float Temperature::getVal()
{
   float minValue = 15;
   float maxValue = 25;

    data = aleaGenVal(minValue, maxValue);
    return data;

}