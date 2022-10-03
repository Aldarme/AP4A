
#include "Light.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <string.h>

Light::Light()
{
  strcpy(m_unite,"Candela");

};
Light::Light(const char unite1[])
{
    strcpy(m_unite,unite1);
  //  cout<<"\n"<<unite;
};
char* Light::getUnite()
{
  return m_unite;
}
void Light::setUnite(const char unite2[])
{
    strcpy(m_unite,unite2);
}
Light::Light(const Light& autre)
{
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
}
Light& Light::operator=(const Light& autre)
{
   
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
    return *this;
}
