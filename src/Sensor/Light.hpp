/**
 * @file Light.hpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de lumière
 * @version 1
 * @date 2022-09-28
 */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"

/**
 * @class Light
 * @brief hérite de Sensor et génère des valeurs de lumière
 * 
 */
class Light : public Sensor
{
  public:
    Light();
    Light(const Light& other_p);
    virtual ~Light(){};
    Light& operator=(const Light& other_p);
};

#endif