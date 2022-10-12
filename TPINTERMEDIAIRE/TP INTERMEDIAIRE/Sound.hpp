#pragma once
#include <iostream>
#include "Sensor.hpp"

class Sound:public Sensor{
private :

public:
    Sound() {
        m_value = 10;
        m_maxValue = 50;
        m_minValue = 0;
    };
};

