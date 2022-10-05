/**
 * @author BRICHET_Clement
 * @file Light.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Light.hpp"

Light::Light()
{
    m_value = aleaGenVal();
    m_filename = "light_log.txt";
}

Light::Light(const Light& sourceLight)
{
    m_value = sourceLight.m_value;
    m_filename = sourceLight.m_filename;
}

Light& Light::operator=(const Light& sourceLight)
{
    m_value = sourceLight.m_value;
    m_filename = sourceLight.m_filename;
    return *this;
}

Light::~Light(){}

bool Light::aleaGenVal(void)
{
    srand(time(0));
    //Although lights are most likely to be always on during a fight,
    //We can give the captor a 10% chance to return false.
    return rand()%10==0 ? false : true;
}

void Light::setData(void)
{
    this->m_value = aleaGenVal();
}
