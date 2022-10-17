
#include "Humidity.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

Humidity::Humidity()
{
  strcpy(unite,"%");
};
Humidity::Humidity(const char unite1[])
{
    strcpy(unite,unite1);
  //  cout<<"\n"<<unite;
};
Humidity::Humidity(const Humidity& autre)
{
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
}
Humidity& Humidity::operator=(const Humidity& autre)
{
  
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
    return *this;
}
char* Humidity::getUnite()
{
  return unite;
}
void Humidity::setUnite(const char unite2[])
{
    strcpy(unite,unite2);
}


/*float Humidity::getData()
{
   // std::cout<<"I'm Here";
    return (this->aleaGenVal());
;
}*/
char* Humidity::gettype(){return type;};


/*
float Humidity::aleaGenVal()

{      //valeur Min                                                 valeurMax-valeurMin
        float r3 = 0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(98-0)));
        float rounded_down = floorf(r3 * 100) / 100;   
    
        return rounded_down;
}
*/
