#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

#include <string>

class Light:public Sensor
{
private:

public:
    
    Light();
    Light(const Light& l); 
    Light& operator=(const Light& l); 
    ~Light();

    int aleaGenValue() override; 
    std::string getType() override;
    std::string getUnity() override;

};



#endif // LIGHT_H