#include "Sensor.hpp"
#include "iostream"

float Sensor::aleaGenVal()
{
    return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

float Sensor::getData()
{
    return (m_MIN_VAL + aleaGenVal()) * (m_MAX_VAL - m_MIN_VAL);
}
