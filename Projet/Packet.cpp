#include "Packet.hpp"

packet packet::operator=(const packet& param_p)
{
    m_temp = param_p.m_temp;
    m_press = param_p.m_press;
    m_light = param_p.m_light;
    m_humid = param_p.m_humid;
    return *this;
}