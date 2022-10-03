//
// Created by jules on 01/10/22.
//

#ifndef PROJET_AP4A_TEMPERATURE_HPP
#define PROJET_AP4A_TEMPERATURE_HPP

#include "../sensor.hpp"

class Temperature : public Sensor<float>
{
public:
    Temperature();
    Temperature(const Temperature& param_temp);
    ~Temperature();
    Temperature& operator=(const Temperature& param_temp);
};

#endif //PROJET_AP4A_TEMPERATURE_HPP
