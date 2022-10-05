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

    //Definition of the canonical form
    Temperature();
    Temperature(const Temperature& param_te); 
    Temperature& operator=(const Temperature& param_te); 
    ~Temperature();

    //generate a value for the temperature
    int aleaGenValue() override; 

    //get the type of the sensor
    std::string getType() override;

    //get the unity of the sensor
    std::string getUnity() override;
};

#endif // TEMPERATURE_H