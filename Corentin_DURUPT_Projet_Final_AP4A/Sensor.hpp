/**
 * @author DURUPT Corentin
 * @file Sensor.hpp
 * @date 21/09/2022
 * @brief this header is composed of the mother class Sensor and its different subclasses Temperature, Humidity, Light and Pressure
*/

#ifndef _SENSOR_H
#define _SENSOR_H

#include<iostream>
#include<random>

/**
 * @class Sensor
 * @brief This class allows to build a Sensor. a Sensor is composed of a name and a data, this data will be gererate randomly.
 */
template <typename T> class Sensor 
{  
private:
    std::string m_sensor_name; //the name of the sensor
    T m_data; //the data of the sensor

public:
    /**
    *@brief the default constructor 
    */
    Sensor();
    /**
    *@brief the destructor 
    */
    ~Sensor();
    /**
    *@brief this constructor initialize the name of the Sensor
    *@param name => a string matches the name of the Sensor
    */
    Sensor(std::string name);
    /**
    *@brief this method allows to get the Sensor's data
    *@return the data of the reliated Sensor type
    */
    T getData();

protected :
    /**
    *@brief this method allows to generate a random data 
    *@return the data of the reliated Sensor type
    */
    virtual T aleaGenVal() = 0;

friend class Scheduler;
friend class Server;

};

#endif // _SENSOR_H



