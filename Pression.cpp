
#include "Pression.hpp"
#include "Server.hpp"
#include "Sensor.hpp"


Pression::Pression()
{

  strcpy(unite,"hPa");
};
Pression::Pression(const char unite1[])
{
    strcpy(unite,unite1);
  //  cout<<"\n"<<unite;
};
Pression::Pression(const Pression& autre)
{
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
}
Pression& Pression::operator=(const Pression& autre)
{
   
    strcpy(unite,autre.unite);
    strcpy(type,autre.type);
    return *this;
}
char* Pression::getUnite()
{
  return unite;
}

void Pression::setUnite(const char unite2[])
{
    strcpy(unite,unite2);
}
/*float Pression::getData()
{
   // std::cout<<"I'm Here";
    return (this->aleaGenVal());
;
}
float Pression::aleaGenVal()

{      //valeur Min                                                 valeurMax-valeurMin
        float r3 = 750 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1050-750)));
        float rounded_down = floorf(r3 * 100) / 100;   
        return rounded_down;
}*/
char* Pression::gettype(){return type;};