/**
 * @author DURUPT Corentin
 * @file Humidity.hpp
 * @date 14/10/2022
 * @brief this header is composed of the sensors' Humidity
*/

#ifndef _HUMIDITY_H
#define _HUMIDITY_H

#include "Sensor.hpp"

/**
 * @class Humidity
 * @brief this class allows to create a Humidity's Sensor 
*/
class Humidity : public Sensor<float> 
{
public :
    /**
    *@brief the default constructor 
    */
    Humidity();
    /**
    *@brief the destructor 
    */
    ~Humidity();
    /**
    *@brief the constructeur which allows to initialize the name of the sensor
    *@param name => the sensor's name
    */
    Humidity(std::string name);
protected :
    /**
    *@brief this method allows to generate a random Humidity's data 
    *@return the data with a float type
    */
    float aleaGenVal();
};

#endif // _HUMIDITY_H