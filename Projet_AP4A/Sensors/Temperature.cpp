//
// Created by jules on 01/10/22.
//

#include "Temperature.hpp"

Temperature::Temperature()
{
    srand(time(nullptr));
    this->m_maxValue = 30;
    this->m_minValue = 20;
}