/**
 * @author BRICHET_Clement
 * @file Temperature.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Temperature.hpp"
#include "Sensor.hpp"

Temperature::Temperature()
{
    m_value = aleaGenVal();
    m_filename = "temperature_log.txt";
}

Temperature::Temperature(const Temperature& sourceTemperature)
{
    m_value = sourceTemperature.m_value;
    m_filename = sourceTemperature.m_filename;
}

Temperature& Temperature::operator=(const Temperature& sourceTemperature)
{
    m_value = sourceTemperature.m_value;
    m_filename = sourceTemperature.m_filename;
    return *this;
}

Temperature::~Temperature(){}

float Temperature::aleaGenVal(void)
{
    srand(time(0));
    //A source indicates the temperature during a flight is between 23 and 25°C.
    return (rand()%40)/20.0+23.0;
}

void Temperature::setData(void)
{
    this->m_value = aleaGenVal();
}