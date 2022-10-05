#include "Temperature.hpp"
#include <stdlib.h>

//Definition of the canonical form
Temperature::Temperature() 
{
    this->m_value = 0;  
    this->m_type = "Temperature";
    this->m_unity = "C";
}

Temperature::Temperature(const Temperature& param_te) 
{
    this->m_value = param_te.m_value; 
    this->m_type = param_te.m_type;
    this->m_unity = param_te.m_unity;
}

Temperature& Temperature::operator=(const Temperature& param_te)
{
    this->m_value = param_te.m_value; 
    this->m_type = param_te.m_type;
    this->m_unity = param_te.m_unity;
    return *this; 
}

Temperature::~Temperature() 
{
}

//generate a value for the temperature
int Temperature::aleaGenValue()
{
    return (rand()%10 + 20); //temp between 20 and 30
}

//get the type of the sensor
std::string Temperature::getType() 
{
    return this->m_type; 
}

//get the unity of the sensor
std::string Temperature::getUnity() 
{
    return this->m_unity; 
}

