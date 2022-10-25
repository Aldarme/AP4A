#include "Light.hpp"
#include<stdlib.h>
bool light::aleaGenVal(bool minValue, bool maxValue)
{
    data = true;
    srand(time(0));
    data = (bool)(rand()%(2));

    return data;
}


bool light::getVal()
{

    data = aleaGenVal(minValue, maxValue);
    return data;

}