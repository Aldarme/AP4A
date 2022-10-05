/**
 * @author  gilles_maurer
 * @file    Sensor.hpp
 * @date    03/10/2022
 * @brief   Parent class of all sensors, virtual class
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <string>

class Sensor 
{
protected:
    int m_value;
    std::string m_type; 
    std::string m_unity;
    virtual std::string getType() = 0;
    virtual std::string getUnity() = 0;
    virtual int aleaGenValue() = 0; 

public: 

    //Definition of the canonical form
    Sensor();
    Sensor(const Sensor& param_se); 
    Sensor& operator=(const Sensor& param_se); 
    ~Sensor();

    //get the value of the sensor : call the aleaGenValue() function of the right child
    int getData();

    //get the type of the sensor : call the getType() function of the right child
    std::string getSensorType();

    //get the unity of the sensor : call the getUnity() function of the right child
    std::string getSensorUnity();
};

#endif // SENSOR_H


