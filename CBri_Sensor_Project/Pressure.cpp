/**
 * @author BRICHET_Clement
 * @file Pressure.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Pressure.hpp"

Pressure::Pressure()
{
    m_value = aleaGenVal();
    m_filename = "pressure_log.txt";
}

Pressure::Pressure(const Pressure& sourcePressure)
{
    m_value = sourcePressure.m_value;
    m_filename = sourcePressure.m_filename;
}

Pressure& Pressure::operator=(const Pressure& sourcePressure)
{
    m_value = sourcePressure.m_value;
    m_filename = sourcePressure.m_filename;
    return *this;
}

Pressure::~Pressure(){}

int Pressure::aleaGenVal(void)
{
    srand(time(0));
    //A source indicates that the pressure into a plane can range from 0.75atm to 0.81atm.
    //Thus, it will range between 0.75*1.013*10^5=75975Pa and 0.81*1.013*10^5=82053Pa.
    return rand()%6078+75975;
}

void Pressure::setData(void)
{
    this->m_value = aleaGenVal();
}
