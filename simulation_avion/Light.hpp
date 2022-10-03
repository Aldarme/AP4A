/**
 * @author  gilles_maurer
 * @file    Light.hpp
 * @date    03/10/2022
 * @brief   Child class of Sensor, light sensor
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

#include <string>

class Light:public Sensor
{
private:

public:
    
    Light();
    Light(const Light& param); 
    Light& operator=(const Light& param); 
    ~Light();

    int aleaGenValue() override; 
    std::string getType() override;
    std::string getUnity() override;

};



#endif // LIGHT_H