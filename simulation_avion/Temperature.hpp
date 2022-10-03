/**
 * @author  gilles_maurer
 * @file    Temperature.hpp
 * @date    03/10/2022
 * @brief   Child class of Sensor, temperature sensor
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

#include <string>

class Temperature:public Sensor
{
private:

public:

    Temperature();
    Temperature(const Temperature& param); 
    Temperature& operator=(const Temperature& param); 
    ~Temperature();

    int aleaGenValue() override; 
    std::string getType() override;
    std::string getUnity() override;

};

#endif // TEMPERATURE_H