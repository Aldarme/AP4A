#include <iostream>
#include "Server.hpp"
#include "Sensor.hpp"
#include <string.h>
#include <math.h>
//#include <unistd.h>
Sensor::Sensor():version(1.2)
{
 // cout<<"I'm here in constructeur par defaut sensor !\n";
}
Sensor::Sensor(const Sensor & autre)
{
 //  cout<<"I'm here in recopie sensor\n";
    
    version=autre.version;
}

Sensor& Sensor::operator=(const Sensor & autre)
{
  // cout<<"I'm here in affectation\n";

    version=autre.version;
    return *this;
}

template<class T> T Sensor::getData(char type[],char unite[])
{
    
    return (this->aleaGenVal<T>(type,unite));
;
}
template<class T> T Sensor::aleaGenVal(char typeofsensor[],char unite[])
{    
    if (strcmp(typeofsensor,"Temperature")==0)
    {      //valeur Min                                                 valeurMax-valeurMin
      T r3 = 20 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(30-20)));
      float rounded_down = floorf(r3 * 100) / 100;
      if(strcmp(unite,"Celsius")==0)//si l'unite est Celsius
      {return rounded_down;}
      return rounded_down*1.8+32;//sinon convertir a fahrenheit
    }
    else if(strcmp(typeofsensor,"Humidity")==0)
    {      //valeur Min                                                 valeurMax-valeurMin
        float r4 = 50 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(98-50)));
        float rounded_down = floorf(r4 * 100) / 100;
       return rounded_down;
    }
    else if(strcmp(typeofsensor,"Light")==0)
    { 
        return 0 + (rand() % (1 - 0 + 1)) == 1;
    }
    else 
    {         //valeur Min                                                 valeurMax-valeurMin
        float r3 = 750 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1050-750)));
        int rounded_down = floorf(r3 * 100) / 100;   
        if(strcmp(unite,"hPa")==0)
      {return rounded_down;}//si l'unite est hpa
      return rounded_down*100;  //sinon convertir a bar
    }
    return 0;

    
}

