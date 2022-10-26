/**
 * @file Humidity.hpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs d'humidité
 * @version 2
 * @date 2022-09-28
 */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

/**
 * @class Humidity
 * @brief hérite de Sensor et génère des valeurs d'humidité
 */
class Humidity : public Sensor<float>
{
  public:
    Humidity();
    Humidity(const Humidity& other_p);
    virtual ~Humidity(){};
    Humidity& operator=(const Humidity& other_p);

    /**
     * @brief héritée de la classe sensor, génère aléatoirement un float 
     * 
     * @return float 
     */
    float aleaGenVal() override;
};

#endif