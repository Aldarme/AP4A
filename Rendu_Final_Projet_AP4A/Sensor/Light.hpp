/**
 * @author Augustin Athané
 * @file Light.hpp
 * @date 24/09/2022
 * @brief Senor Light, classe fille de Sensor
 * */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <iostream>
#include <cstdlib>
#include "Sensor.hpp"

class Light : public Sensor
{
    protected :
        bool value;

    public :
        Light();
        Light(const Light &other);
        ~Light();
        void startSimulation() override;
        bool getData();
      
};

#endif //LIGHT_HPP