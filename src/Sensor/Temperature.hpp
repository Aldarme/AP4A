/**
 * @file Temperature.hpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de température
 * @version 1
 * @date 2022-09-28
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

/**
 * @class Temperature
 * @brief hérite de Sensor et génère des valeurs de température
 */
class Temperature : public Sensor
{
  public:
    Temperature();
    Temperature(const Temperature& other_p);
    virtual ~Temperature(){};
    Temperature& operator=(const Temperature& other_p);

};

#endif