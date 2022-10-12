/**
 * @author lois ROGER
 * @file Humidity.hpp
 * @date 05/09/2022
 * @brief capteur d'humidité
*/

#ifndef HUMIDITY_H
#define HUMIDiTY_H
#include "Sensor.hpp"

class Humidity : public Sensor
{
    public:
        int m_hmini;
        int m_hmaxi;
        humidity();

};

#endif