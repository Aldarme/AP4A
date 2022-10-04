/**
 * @author Céliane ALLAIRE
 * @file Packet.cpp
 * @date 04/10/2022
 * @brief 
 * */

#include "Packet.hpp"

void Packet::setData(const int humid_p, const int light_p, const int press_p, const int temp_p){
    m_humid = humid_p;
    m_light = light_p;
    m_press = press_p;
    m_temp = temp_p;
}
