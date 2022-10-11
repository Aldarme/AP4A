/**
 * @file Packet.cpp
 * @author Aurélien PETRA
 * @brief Permet regrouper des valeur de température, pression, lumière et pression au même endroit
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Packet.hpp"

packet &packet::operator=(const packet &param_p)
{
    m_temp = param_p.m_temp;
    m_press = param_p.m_press;
    m_light = param_p.m_light;
    m_humid = param_p.m_humid;
    return *this;
}