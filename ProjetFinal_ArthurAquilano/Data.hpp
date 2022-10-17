/**
 * @author Arthur
 * @file Data.hpp
 * @date 03/10/22
 * @brief Déclaration des classes des data
 */

//DEFINE_GUARDS
#ifndef DATA_H
#define DATA_H

#include "Sensor.hpp"

/**
* @class DataTemperature
* @brief Déclaration de la classe DataTemperature
*/
class DataTemperature: virtual public Sensor<float>
{
public:
    /** 
    * @brief La methode permet d'affecter une valeur grâce à la méthode aleaGenVal() de la classe Sensor
    * @return int
    * @param Aucun
    */
    float getVal();
};

/**
* @class DataHumidity
* @brief Declaration de la classe DataHumidity
*/
class DataHumidity: virtual public Sensor<float>
{
public:
    float getVal();
};

/**
* @class DataLight
* @brief Declaration de la classe DataLight
*/
class DataLight: virtual public Sensor<bool>
{
public:
    bool getVal();
};

/**
* @class DataPressure
* @brief Declaration de la classe DataPressure
*/
class DataPressure: virtual public Sensor<int>
{
public:
    int getVal();
};

#endif //DATA.H