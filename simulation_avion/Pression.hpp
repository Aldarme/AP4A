/**
 * @author  gilles_maurer
 * @file    Pression.hpp
 * @date    03/10/2022
 * @brief   Child class of Sensor, pression sensor
 */

#ifndef PRESSION_H
#define PRESSION_H

#include "Sensor.hpp" 

#include <string>

class Pression:public Sensor
{
private:

public:

    Pression();
    Pression(const Pression& param); 
    Pression& operator=(const Pression& param); 
    ~Pression();

    int aleaGenValue() override;
    std::string getType() override;
    std::string getUnity() override; 

};

#endif // PRESSION_H