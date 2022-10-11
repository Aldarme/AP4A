/**
 * @file Sensor.cpp
 * @author Aurélien PETRA
 * @brief Classe mère de tous les capteurs, elle possède des méthodes génériques utilent à tous les capteurs
 * @version 0.1
 * @date 2022-10-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Sensor.hpp"
using namespace std;

sensor &sensor::operator=(const sensor &param_s)
{
    m_min = param_s.m_min;
    m_max = param_s.m_max;
    return *this;
}

int sensor::aleaGenVal()
{
    srand((int)time(0));
    return rand() % (m_max + 1 - m_min) + m_min;
}