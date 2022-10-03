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
        int value;
        std::string type; 
        std::string unity;
        virtual std::string getType() = 0;
        virtual std::string getUnity() = 0;
        virtual int aleaGenValue() = 0; 

    public: 

        Sensor();
        Sensor(const Sensor& param); 
        Sensor& operator=(const Sensor& param); 
        ~Sensor();

        int getData();
        std::string getSensorType();
        std::string getSensorUnity();
};


#endif // SENSOR_H


