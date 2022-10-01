//
// Created by jules on 01/10/22.
//

#include "Humidite.hpp"

Humidite::Humidite()
{
    srand(time(nullptr));
    this->m_minValue = 40;
    this->m_maxValue = 60;
}