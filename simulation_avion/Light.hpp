#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

class Light:public Sensor
{
private:
    int value; 

public:
    
    Light();
    Light(const Light& l); 
    Light& operator=(const Light& l); 
    Light& operator=(float l); 
    ~Light();

    int aleaGenValue() override; 

};



#endif // LIGHT_H