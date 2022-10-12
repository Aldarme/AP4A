#pragma once
#include "Sensor.hpp"

class Light : public Sensor
{
public:
    Light() {
        m_value = 10;
        m_maxValue = 50;
        m_minValue = 0;
    }

};