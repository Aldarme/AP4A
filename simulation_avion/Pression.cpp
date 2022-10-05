#include "Pression.hpp"

#include <stdlib.h>

//Definition of the canonical form
Pression::Pression() 
{
    this->m_value = 0;
    this->m_type = "Pression";
    this->m_unity = "hPa";  
}

Pression::Pression(const Pression& param_pr) 
{
    this->m_value = param_pr.m_value;
    this->m_type = param_pr.m_type;
    this->m_unity = param_pr.m_unity; 
}

Pression& Pression::operator=(const Pression& param_pr) 
{
    this->m_value = param_pr.m_value; 
    this->m_type = param_pr.m_type;
    this->m_unity = param_pr.m_unity;
    return *this; 
}

Pression::~Pression() 
{
}

//generate a value for the pression
int Pression::aleaGenValue()
{
    return (rand()%800 + 50); // pression between 50 and 850 hPa
}

//get the type of the sensor
std::string Pression::getType() 
{
    return this->m_type; 
}

//get the unity of the sensor
std::string Pression::getUnity() 
{
    return this->m_unity; 
}