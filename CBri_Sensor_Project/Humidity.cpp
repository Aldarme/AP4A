/**
 * @author BRICHET_Clement
 * @file Humidity.cpp
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#include "Humidity.hpp"

//Default constructor
Humidity::Humidity()
{
    m_value = aleaGenVal();
    m_type = "humidity";
    m_unit = "%";
}

//Constructor by copy
Humidity::Humidity(const Humidity& sourceHumidity_p)
{
    m_value = sourceHumidity_p.m_value;
    m_type = sourceHumidity_p.m_type;
    m_unit = sourceHumidity_p.m_unit;
}

//= operator
Humidity& Humidity::operator=(const Humidity& sourceHumidity_p)
{
    m_value = sourceHumidity_p.m_value;
    m_type = sourceHumidity_p.m_type;
    m_unit = sourceHumidity_p.m_unit;
    return *this;
}

//Destructor
Humidity::~Humidity(){}

float Humidity::aleaGenVal(void)
{
    //srand(time(0));
    //(We don't include it here but in the main so that it doesn't get restarted everytime we call the function.)
    
    //Various sources say the humidity in a plane is around 8 or 10%.
    //Thus, we return a value between 7+0=7% and 7+4=11%.
    return ((rand()%80)/20.0)+7.0;
}

//Setter
void Humidity::setData(void)
{
    this->m_value = aleaGenVal();
}