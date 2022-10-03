
#include "Pression.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include <string.h>

Pression::Pression()
{

  strcpy(m_unite,"hPa");
};
Pression::Pression(const char unite1[])
{
    strcpy(m_unite,unite1);
  //  cout<<"\n"<<unite;
};
Pression::Pression(const Pression& autre)
{
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
}
Pression& Pression::operator=(const Pression& autre)
{
   
    strcpy(m_unite,autre.m_unite);
    strcpy(m_type,autre.m_type);
    return *this;
}
char* Pression::getUnite()
{
  return m_unite;
}

void Pression::setUnite(const char unite2[])
{
    strcpy(m_unite,unite2);
}
