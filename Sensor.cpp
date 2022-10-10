#include <iostream>
#include "Sensor.hpp"


float Sensor::randomValue(float param_minor, float param_major)
{
    static std::default_random_engine rng; //Generating the default random engine ?
    std::uniform_real_distribution<float> dist(param_minor, param_major); //Generating the distribution for the random engine ?
    return dist(rng);
}; //Generating a random float between a and b using a uniform distribution ? (swtich to normal distribution for more realism ?)

static std::vector<float> Sensor::getData() //Creating an non-limited array (vector)
{
    return
    {
        Temperature::getTemperature(),Humidity::getHumidity(),Light::getLight(),Pression::getPression()
    };
}; //Collecting the 4 floats data from each sensor, and package them in an array
