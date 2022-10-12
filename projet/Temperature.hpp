/**
 * @author lois ROGER
 * @file Temperature.hpp
 * @date 05/09/2022
 * @brief capteur de température 
*/

#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "Sensor.hpp"

class Temperature : public Sensor
{
    public:
        int m_tmini;
        int m_tmaxi;
        Temperature();
};

#endif