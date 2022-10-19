/**
 * @author BRICHET_Clement
 * @file Pressure.cpp
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#include "Pressure.hpp"

//Default constructor
Pressure::Pressure()
{
    m_value = aleaGenVal();
    m_type = "pressure";
    m_unit = "Pa";
}

//Constructor by copy
Pressure::Pressure(const Pressure& sourcePressure_p)
{
    m_value = sourcePressure_p.m_value;
    m_type = sourcePressure_p.m_type;
    m_unit = sourcePressure_p.m_unit;
}

//= operator
Pressure& Pressure::operator=(const Pressure& sourcePressure_p)
{
    m_value = sourcePressure_p.m_value;
    m_type = sourcePressure_p.m_type;
    m_unit = sourcePressure_p.m_unit;
    return *this;
}

//Destructor
Pressure::~Pressure(){}

int Pressure::aleaGenVal(void)
{
    //srand(time(0));
    //(We don't include it here but in the main so that it doesn't get restarted everytime we call the function.)
    
    //A source indicates that the pressure into a plane can range from 0.75atm to 0.81atm.
    //Thus, it will range between 0.75*1.013*10^5=75975Pa and 0.81*1.013*10^5=82053Pa.
    return rand()%6078+75975;
}

//Setter
void Pressure::setData(void)
{
    this->m_value = aleaGenVal();
}
