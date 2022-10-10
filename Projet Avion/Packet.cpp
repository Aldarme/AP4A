/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 4/10/2022
 *  @brief This file contains implementations of the class "Packet"
 */

#include "Packet.hpp"

int Packet::getTemperature()
{
    return this->m_temperature;
}
int Packet::getPression()
{
    return this->m_pression;
}
int Packet::getHumidity()
{
    return this->m_humidity;
}
int Packet::getLight()
{
    return this->m_light;
}
void Packet::setVal(int temperature_p,int pression_p,int humidity_p,int light_p)
{
    this->m_temperature = temperature_p;
    this->m_pression = pression_p;
    this->m_humidity = humidity_p;
    this->m_light = light_p;
}