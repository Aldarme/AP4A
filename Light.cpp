
#include "Light.hpp"
#include "Server.hpp"
#include "Sensor.hpp"


Light::Light()
{
  strcpy(unite,"Candela");

};
Light::Light(const char unite1[])
{
    strcpy(unite,unite1);
  //  cout<<"\n"<<unite;
};
char* Light::getUnite()
{
  return unite;
}
void Light::setUnite(const char unite2[])
{
    strcpy(unite,unite2);
}
Light::Light(const Light& autre)
{
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
}
Light& Light::operator=(const Light& autre)
{
   
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
    return *this;
}
char* Light::gettype(){return type;};


