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

    //Definition of the canonical form
    Humidity();
    Humidity(const Humidity& param_hu); 
    Humidity& operator=(const Humidity& param_hu); 
    ~Humidity();

    //generate a value for the humidity 
    int aleaGenValue() override; 

    //get the type of the sensor
    std::string getType() override;

    //get the unity of the sensor
    std::string getUnity() override;

};


#endif // HUMIDITY_H