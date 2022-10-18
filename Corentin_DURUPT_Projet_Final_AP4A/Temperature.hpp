/**
 * @author DURUPT Corentin
 * @file Temperature.hpp
 * @date 14/10/2022
 * @brief this header is composed of the sensors' Temperature
*/

#ifndef _TEMPERATURE_H
#define _TEMPERATURE_H

#include "Sensor.hpp"
#include <random>

/**
 * @class Temperature
 * @brief this class allows to create a Temperature's Sensor 
*/
class Temperature : public Sensor<float>
{
public :
    /**
    *@brief the default constructor 
    */
    Temperature();
    /**
    *@brief the destructor 
    */
    ~Temperature();
    /**
    *@brief the constructeur which allows to initialize the name of the sensor
    *@param name => the sensor's name
    */
    Temperature(std::string name);
protected :
    /**
    *@brief this method allows to generate a random Temperature's data 
    *@return the data with a float type
    */
    float aleaGenVal();
};

#endif // _TEMPERATURE_H