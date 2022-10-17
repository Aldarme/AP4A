#include "Temperature.hpp"
#include "Server.hpp"
#include "Sensor.hpp"
#include "Sensor.hpp"
#include <string.h>
#include <math.h>


Temperature::Temperature()
{

    strcpy(unite,"Celsius");
};
Temperature::Temperature(const char unite1[])
{
    strcpy(unite,unite1);
   // cout<<unite;
};
Temperature::Temperature(const Temperature& autre)
{
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
}
Temperature& Temperature::operator=(const Temperature& autre)
{
    
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
    return *this;
}

char* Temperature::getUnite()
{
    return unite;
}
char* Temperature::gettype(){return type;};
void Temperature::setUnite(const char unite2[])
{
    strcpy(unite,unite2);
}


