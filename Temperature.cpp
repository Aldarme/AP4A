#include "Temperature.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include "Sensor.hpp"
#include <string.h>


Temperature::Temperature()
{

    strcpy(m_unite,"Celsius");
};
Temperature::Temperature(const char unite1[])
{
    strcpy(m_unite,unite1);
   // cout<<unite;
};
Temperature::Temperature(const Temperature& autre)
{
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
}
Temperature& Temperature::operator=(const Temperature& autre)
{
    
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
    return *this;
}

char* Temperature::getUnite()
{
    return m_unite;
}
void Temperature::setUnite(const char unite2[])
{
    strcpy(m_unite,unite2);
}

