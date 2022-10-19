/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Light
*/


#include "Light.hpp"

Light::Light() : Sensor(0, 1){};
bool Light::getData()
{   
    return rand() % 2;
}
