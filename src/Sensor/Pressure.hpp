/**
 * @file Pressure.hpp
 * @author Loric Ravassard
 * @brief hérite de Sensor et génère des valeurs de pression
 * @version 2
 * @date 2022-09-28
 */

#ifndef PRESSURE_H
#define PRESSURE_H

#include "Sensor.hpp"

/**
 * @class Pressure
 * @brief hérite de Sensor et génère des valeurs de pression
 */
class Pressure : public Sensor<int>
{
  public:
    Pressure();
    Pressure(const Pressure& other_p);
    virtual ~Pressure(){};
    Pressure& operator=(const Pressure& other_p);

    /**
     * @brief héritée de la classe sensor, génère aléatoirement un int
     * 
     * @return int 
     */
    int aleaGenVal() override;
};

#endif