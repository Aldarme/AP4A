#include "Light.hpp"
#include "stdlib.h"


//Definition of the canonical form
Light::Light() 
{
    this->m_value = 0;  
    this->m_type = "Light";
    this->m_unity = "on/off";
}

Light::Light(const Light& param_li) 
{
    this->m_value = param_li.m_value; 
    this->m_type = param_li.m_type;
    this->m_unity = param_li.m_unity;
}

Light& Light::operator=(const Light& param_li) 
{
    this->m_value = param_li.m_value; 
    this->m_type = param_li.m_type;
    this->m_unity = param_li.m_unity;
    return *this; 
}

Light::~Light() 
{
}

//generate a value for the light
int Light::aleaGenValue()
{
    return rand()%2; // light on or off
}

//get the type of the sensor
std::string Light::getType() 
{
    return this->m_type; 
}

//get the unity of the sensor
std::string Light::getUnity() 
{
    return this->m_unity; 
}

