
#include "Humidity.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <string.h>
Humidity::Humidity()
{
  strcpy(m_unite,"%");
};
Humidity::Humidity(const char unite1[])
{
    strcpy(m_unite,unite1);
  //  cout<<"\n"<<unite;
};
Humidity::Humidity(const Humidity& autre)
{
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
}
Humidity& Humidity::operator=(const Humidity& autre)
{
  
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
    return *this;
}
char* Humidity::getUnite()
{
  return m_unite;
}
void Humidity::setUnite(const char unite2[])
{
    strcpy(m_unite,unite2);
}

