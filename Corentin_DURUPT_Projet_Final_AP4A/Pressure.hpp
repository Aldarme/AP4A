/**
 * @author DURUPT Corentin
 * @file Pressure.hpp
 * @date 14/10/2022
 * @brief this header is composed of the sensors' Pressure
*/

#ifndef _PRESSURE_H
#define _PRESSURE_H

#include "Sensor.hpp"

/**
 * @class Pressure
 * @brief this class allows to create a Pressure's Sensor 
*/
class Pressure : public Sensor<int>
{
public :
    /**
    *@brief the default constructor 
    */
    Pressure();
    /**
    *@brief the destructor 
    */
    ~Pressure();
    /**
    *@brief the constructeur which allows to initialize the name of the sensor
    *@param name => the sensor's name
    */
    Pressure(std::string name);
protected :
    /**
    *@brief this method allows to generate a random Pressure's data 
    *@return the data with a int type
    */
    int aleaGenVal();
};

#endif // _PRESSURE_H