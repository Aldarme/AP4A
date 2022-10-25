#include <iostream>
#include "Humidity.hpp"


float Humidity::getData()
{
    return Humidity::randomValue(35.0f,60.0f); //Generating a random number between 35.0 and 60.0 (%age of humidity)
}; //Returning the humidity value

float Humidity::randomValue(float param_minor, float param_major)
{
    float random = ((float)rand()) / (float)RAND_MAX; //Generating a random number between 0 and 1
    return param_minor + (param_major - param_minor) * random; //Generating a random number between param_minor and param_major
}; //Generating a random float between param_minor and param_major

std::ostream &operator<<(std::ostream &os, const Humidity &humidity) {
    return os;
};