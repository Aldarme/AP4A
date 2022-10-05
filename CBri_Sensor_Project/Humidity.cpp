/**
 * @author BRICHET_Clement
 * @file Humidity.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Humidity.hpp"

Humidity::Humidity()
{
    m_value = aleaGenVal();
    m_filename = "humidity_log.txt";
}

Humidity::Humidity(const Humidity& sourceHumidity)
{
    m_value = sourceHumidity.m_value;
    m_filename = sourceHumidity.m_filename;
}

Humidity& Humidity::operator=(const Humidity& sourceHumidity)
{
    m_value = sourceHumidity.m_value;
    m_filename = sourceHumidity.m_filename;
    return *this;
}

Humidity::~Humidity(){}

float Humidity::aleaGenVal(void)
{
    srand(time(0));
    //Various sources say the humidity in a plane is around 8 or 10%.
    //Thus, we return a value between 7+0=7% and 7+4=11%.
    return ((rand()%80)/20.0)+7.0;
}

void Humidity::setData(void)
{
    this->m_value = aleaGenVal();
}