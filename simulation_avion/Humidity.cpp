#include "Humidity.hpp"
#include "stdlib.h"

#include <string>

//Definition of the canonical form
Humidity::Humidity() 
{
    this->m_value = 0;  
    this->m_type = "Humidity";
    this->m_unity = "%";
}

Humidity::Humidity(const Humidity& param_hu) 
{
    this->m_value = param_hu.m_value; 
    this->m_type = param_hu.m_type;
    this->m_unity = param_hu.m_unity;
}

Humidity& Humidity::operator=(const Humidity& param_hu) 
{
    this->m_value = param_hu.m_value; 
    this->m_type = param_hu.m_type;
    this->m_unity = param_hu.m_unity;
    return *this; 
}

Humidity::~Humidity() 
{
}

//generate a value for the humidity
int Humidity::aleaGenValue()
{
    return rand()%25 + 10; //humidity between 10 and 35 
}

//get the type of the sensor 
std::string Humidity::getType() 
{
    return this->m_type; 
}

//get the unity of the sensor
std::string Humidity::getUnity() 
{
    return this->m_unity; 
}
