/**
 * @author BRICHET_Clement
 * @file Light.cpp
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#include "Light.hpp"

//Default constructor
Light::Light()
{
    m_value = aleaGenVal();
    m_type = "light";
    m_unit = "";
}

//Constructor by copy
Light::Light(const Light& sourceLight_p)
{
    m_value = sourceLight_p.m_value;
    m_type = sourceLight_p.m_type;
    m_unit = sourceLight_p.m_unit;
}

//= operator
Light& Light::operator=(const Light& sourceLight_p)
{
    m_value = sourceLight_p.m_value;
    m_type = sourceLight_p.m_type;
    m_unit = sourceLight_p.m_type;
    return *this;
}

//Destructor
Light::~Light(){}

bool Light::aleaGenVal(void)
{
    //srand(time(0));
    //(We don't include it here but in the main so that it doesn't get restarted everytime we call the function.)
    
    //Although lights are most likely to be always on during a fight,
    //We can give the captor a 10% chance to return false.
    return rand()%10==0 ? false : true;
}

//Setter
void Light::setData(void)
{
    this->m_value = aleaGenVal();
}
