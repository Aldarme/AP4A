/**
 * @author Augustin Athané
 * @file Humidity.hpp
 * @date 24/09/2022
 * @brief Senor Humidity, classe fille de Sensor
 * */

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

#include <iostream>
#include <cstdlib>
#include "Sensor.hpp"

class Humidity : public Sensor
{
    protected :
        float value;

    public :
        Humidity();
        Humidity(const Humidity &other);
        ~Humidity();
        void startSimulation() override;
        float getData();

};


#endif //HUMIDITY_HPP