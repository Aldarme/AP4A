#include "Humidity.hpp"
#include <iostream>

float Humidity::DataHumidity()
{
    return (getData(m_max, m_min));
}