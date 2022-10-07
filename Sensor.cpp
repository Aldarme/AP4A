#include <random>
#include <ctime>

#include "Sensor.hpp"

Sensor::Sensor(float p_MIN_VAL, float p_MAX_VAL)
{
    srand(time(NULL));
    m_MIN_VAL = p_MIN_VAL;
    m_MAX_VAL = p_MAX_VAL;
}

float Sensor::aleaGenVal()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

float Sensor::getData()
{
    return (m_MIN_VAL + aleaGenVal()) * (m_MAX_VAL - m_MIN_VAL);
}