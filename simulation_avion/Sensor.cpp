#include "Sensor.hpp"

#include <stdlib.h>
#include <string>


//Definition of the canonical form
Sensor::Sensor() 
{
    //les atributs sont initialisés dans les enfants de Sensor   
}

Sensor::Sensor(const Sensor& param_se) 
{
    this->m_value = param_se.m_value; 
    this->m_type = param_se.m_type;
    this->m_unity = param_se.m_unity;
}

Sensor& Sensor::operator=(const Sensor& param_se) 
{
    this->m_value = param_se.m_value;
    this->m_type = param_se.m_type;
    this->m_unity = param_se.m_unity;
    return *this;
}

Sensor::~Sensor() 
{
}

//get the value of the sensor : call the aleaGenValue() function of the right child
int Sensor::getData() 
{
    return this->aleaGenValue();  
}

//get the type of the sensor : call the getType() function of the right child
std::string Sensor::getSensorType() 
{
    return this->getType(); 
}

//get the unity of the sensor : call the getUnity() function of the right child
std::string Sensor::getSensorUnity() 
{
    return this->getUnity(); 
}
