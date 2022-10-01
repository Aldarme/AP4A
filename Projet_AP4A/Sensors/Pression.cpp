//
// Created by jules on 01/10/22.
//

#include "Pression.hpp"


Pression::Pression()
{
    srand(time(nullptr));
    this->m_minValue = 76;
    this->m_maxValue = 81;
}

int Pression::aleaGenVal(int param_minVal, int param_maxVal)
{
    return std::rand() % (param_maxVal - param_minVal) + param_minVal;
}

int Pression::getData()
{
    return this->aleaGenVal(this->m_minValue, this->m_maxValue);
}