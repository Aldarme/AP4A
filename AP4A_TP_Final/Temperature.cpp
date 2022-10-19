#include "Temperature.hpp"
#include <iostream>

float Temperature::DataTemperature()
{
    return (getData(m_max, m_min));
}