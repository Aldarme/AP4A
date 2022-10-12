/**
 * @author lois ROGER
 * @file Pression.hpp
 * @date 05/09/2022
 * @brief capteur de pression
*/

#ifndef PRESSION_H
#define PRESSION_H
#include "Sensor.hpp"

class Pression : public Sensor
{
    public:
        int m_pmini;
        int m_pmaxi;
        Pression();


};

#endif