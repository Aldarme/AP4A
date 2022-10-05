#include "Sensor.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Sensor::Sensor()
{
    this->m_data = 0;
    m_specs = new const char*[LENGTH];
}

void Sensor::refreshData()
{
    m_data = aleaGenVal();
}

Sensor::Sensor(const Sensor& sensor_p)
{
    this->m_data = sensor_p.m_data;
    m_specs = new const char*[LENGTH];
    if(m_specs)
    {
        for(int i = 0; i < LENGTH; i++){
            this->m_specs[i] = sensor_p.m_specs[i];
        }
    }
}

Sensor& Sensor::operator=(const Sensor& sensor_p)
{
    this->m_data = sensor_p.m_data;
    if(m_specs)
    {
        for(int i = 0; i < LENGTH; i++){
            this->m_specs[i] = sensor_p.m_specs[i];
        }
    }
    return *this;
}

void Sensor::setSpecifications(const char* spec1_p, const char* spec2_p)
{
    this->m_specs[0] = spec1_p;
    this->m_specs[1] = spec2_p;
}

int Sensor::getData()
{
    return m_data;
}

void Sensor::setData(int data_p) 
{
    this->m_data = data_p;
}

int Sensor::aleaGenVal()
{
    return rand() % 100;
}