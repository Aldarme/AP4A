#include <iostream>
#include "Humidity.hpp"


float Humidity::getHumidity()
{
    return randomValue(35,60); //Generating a random number between 35 and 60 (%age of humidity)
}