#pragma once
#include "Sensor.hpp"
#include <iostream>
class Temperature : public Sensor
{
public:

    Temperature() {
        m_value = 0;
        m_maxValue = 0;
        m_minValue = 0;
    };

}