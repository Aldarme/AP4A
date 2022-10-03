/**
 * @author  gilles_maurer
 * @file    Humidity.hpp
 * @date    03/10/2022
 * @brief   Child class of Sensor, humidity sensor
 */


#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

#include <string> 

class Humidity: public Sensor 
{
private:

public:
    Humidity();
    Humidity(const Humidity& param); 
    Humidity& operator=(const Humidity& param); 
    ~Humidity();

    int aleaGenValue() override; 
    std::string getType() override;
    std::string getUnity() override;

};


#endif // HUMIDITY_H