/**
 * @author BRICHET_Clement
 * @file Temperature.cpp
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#include "Temperature.hpp"
#include "Sensor.hpp"

Temperature::Temperature()
{
    m_value = aleaGenVal();
    m_type = "temperature";
    m_unit = "°C";
}

Temperature::Temperature(const Temperature& sourceTemperature_p)
{
    m_value = sourceTemperature_p.m_value;
    m_type = sourceTemperature_p.m_type;
    m_unit = sourceTemperature_p.m_unit;
}

Temperature& Temperature::operator=(const Temperature& sourceTemperature_p)
{
    m_value = sourceTemperature_p.m_value;
    m_type = sourceTemperature_p.m_type;
    m_unit = sourceTemperature_p.m_unit;
    return *this;
}

Temperature::~Temperature(){}

float Temperature::aleaGenVal(void)
{
    //srand(time(0));
    //(We don't include it here but in the main so that it doesn't get restarted everytime we call the function.)

    //A source indicates the temperature during a flight is between 23 and 25°C.
    return (rand()%40)/20.0+23.0;
}

void Temperature::setData(void)
{
    this->m_value = aleaGenVal();
}