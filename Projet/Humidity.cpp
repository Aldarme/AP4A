/**
 * @file Humidity.cpp
 * @author Aurélien PETRA
 * @brief Classe fille de "sensor", détermine et génère des valeurs d'humidité (entre 5 et 10)
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Humidity.hpp"

humidity &humidity::aleaGenVal()
{
    srand((unsigned)time(NULL));
    int sign = (int)(rand() % 100) % 2;
    float random = (float)(rand() % 101) / 100;

    if (m_data - random < 5)
    {
        sign = 1;
    }
    else if (m_data + random > 10)
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

humidity &humidity::aleaInitVal()
{
    srand((unsigned)time(NULL));
    int sign = (int)(rand() % 100) % 2;
    float random = (float)(rand() % 251) / 100;

    if (sign == 1)
    {
        m_data = 7.5 + random;
    }
    else
    {
        m_data = 7.5 - random;
    }

    return *this;
}