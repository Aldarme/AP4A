/**
 * @author lois ROGER
 * @file Light.hpp
 * @date 05/09/2022
 * @brief capteur de lumière
*/

#ifndef LIGHT_H
#define LIGHT_H
#include "Sensor.hpp"

class Light : public Sensor<bool>
{
    public:
       bool getVal();
       bool aleaGenVal(bool mini, bool maxi);

};

#endif