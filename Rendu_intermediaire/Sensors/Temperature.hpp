//
// Created by jules on 01/10/22.
//

#ifndef PROJET_AP4A_TEMPERATURE_HPP
#define PROJET_AP4A_TEMPERATURE_HPP

#include "../sensor.hpp"

class Temperature : public Sensor<TYPE>
{
public:
    Temperature();
    Temperature(const Temperature& temp_p);
    ~Temperature();
    Temperature& operator=(const Temperature& temp_p);
};

#endif //PROJET_AP4A_TEMPERATURE_HPP
