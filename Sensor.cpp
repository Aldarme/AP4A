#include <iostream>
#include "Server.hpp"
#include "Sensor.hpp"
#include <string.h>
#include <math.h>
//#include <unistd.h>
Sensor::Sensor():m_version(1.2)
{
 // cout<<"I'm here in constructeur par defaut sensor !\n";
}
Sensor::Sensor(const Sensor & autre)
{
 //  cout<<"I'm here in recopie sensor\n";
    
    m_version=autre.m_version;
}

Sensor& Sensor::operator=(const Sensor & autre)
{
  // cout<<"I'm here in affectation\n";

    m_version=autre.m_version;
    return *this;
}

float Sensor::getData(char type[])
{
    
    return (this->aleaGenVal(type));
;
}
float Sensor::aleaGenVal(char typeofsensor[])
{
   // rand();
    if (strcmp(typeofsensor,"Temperature")==0)
    {      //valeur Min                                                 valeurMax-valeurMin
    float r3 = 20 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(30-20)));
    float rounded_down = floorf(r3 * 100) / 100;   
    
    return rounded_down;
    }
    else if(strcmp(typeofsensor,"Humidity")==0)
    {      //valeur Min                                                 valeurMax-valeurMin
        float r3 = 0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(98-0)));
        float rounded_down = floorf(r3 * 100) / 100;   
    
        return rounded_down;
    }
    else if(strcmp(typeofsensor,"Light")==0)
    {      //valeur Min                                                 valeurMax-valeurMin
        float r3 = 0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1-0)));
        float rounded_down = floorf(r3 * 100) / 100;   
        return rounded_down;
    }
    else 
    {         //valeur Min                                                 valeurMax-valeurMin
        float r3 = 750 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1050-750)));
        float rounded_down = floorf(r3 * 100) / 100;   //pour afficher seulement 2 chiffres apres la virgule
        return rounded_down;
    }
    return 1;
}

