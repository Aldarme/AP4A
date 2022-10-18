/**
 * @author DURUPT Corentin
 * @file Light.hpp
 * @date 14/10/2022
 * @brief this header is composed of the sensors' Light
*/

#ifndef _LIGHT_H
#define _LIGHT_H

#include "Sensor.hpp"

/**
 * @class Light
 * @brief this class allows to create a Light's Sensor 
*/
class Light : public Sensor<bool>
{
public :
    /**
    *@brief the default constructor 
    */
    Light();
    /**
    *@brief the destructor 
    */
    ~Light();
    /**
    *@brief the constructeur which allows to initialize the name of the sensor
    */
    Light(std::string name);
protected :
    /**
    *@brief this method allows to generate a random Light's data 
    *@return the data with a bool type
    */
    bool aleaGenVal();
};

#endif // _LIGHT_H