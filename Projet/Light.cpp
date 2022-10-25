/**
 * @file Light.cpp
 * @author Aurélien PETRA
 * @brief Génère une valeur aléatoire comprise entre 5 et 10 à partir de l'attribut m_data
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Light.hpp"

light_ &light_::aleaGenVal()
{
    return aleaInitVal();
}

light_ &light_::aleaInitVal()
{
    time_t current = time(0);
    tm *ltm = localtime(&current);

    if (ltm->tm_hour > 8 && ltm->tm_hour < 22)
    {
        m_data = false;
    }
    else
    {
        m_data = true;
    }

    return *this;
}