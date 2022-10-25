#include <iostream>
#include "Temperature.hpp"


float Temperature::getData()
{
    return Temperature::randomValue(15.0f,30.0f); //Generating a random number between 15.0 and 30.0 (°C)
}; //Returning the temperature value

float Temperature::randomValue(float param_minor, float param_major)
{
    float random = ((float)rand()) / (float)RAND_MAX; //Generating a random number between 0 and 1
    return param_minor + (param_major - param_minor) * random; //Generating a random number between param_minor and param_major
}; //Generating a random float between param_minor and param_major

std::ostream &operator<<(std::ostream &os, const Temperature &temperature) {
    return os;
}
