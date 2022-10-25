/**
 * @file Pressure.cpp
 * @author Aurélien PETRA
 * @brief Classe fille de "sensor", détermine et génère des valeurs de pression (entre 75 et 81)
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Pressure.hpp"

pressure &pressure::aleaGenVal()
{
    srand((unsigned)time(NULL));
    int sign = (int)(rand() % 100) % 2;
    int random = (int)(rand() % 100) % 2;

    if (m_data - random < 75)
    {
        sign = 1;
    }
    else if (m_data + random > 81)
    {
        sign = 0;
    }

    if (sign == 1)
    {
        m_data = m_data + random;
    }
    else
    {
        m_data = m_data - random;
    }

    return *this;
}

pressure &pressure::aleaInitVal()
{
    srand((unsigned)time(NULL));
    int sign = (int)(rand() % 100) % 2;
    int random = (int)(rand() % 100) % 4;

    if (sign == 1)
    {
        m_data = 78 + random;
    }
    else
    {
        m_data = 78 - random;
    }

    return *this;
}