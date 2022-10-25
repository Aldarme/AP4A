/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 4/10/2022
 *  @brief This file contains implementations of the class "Packet"
 */

#include "Packet.hpp"

float Packet::getTemperature()
{
    return this->m_temperature;
}
int Packet::getPression()
{
    return this->m_pression;
}
float Packet::getHumidity()
{
    return this->m_humidity;
}
bool Packet::getLight()
{
    return this->m_light;
}
void Packet::setVal(float temperature_p,int pression_p,float humidity_p,bool light_p)
{
    this->m_temperature = temperature_p;
    this->m_pression = pression_p;
    this->m_humidity = humidity_p;
    this->m_light = light_p;
}