/**
 * @author Augustin Athané
 * @file Pression.hpp
 * @date 24/09/2022
 * @brief Senor Pression, classe fille de Sensor
 * */

#ifndef PRESSION_HPP
#define PRESSION_HPP

#include <iostream>
#include <cstdlib>
#include "Sensor.hpp"


class Pression : public Sensor
{
    protected :
        int value;

    public :
        Pression();
        Pression(const Pression &other);
        ~Pression();
        void startSimulation() override;
        int getData();
};

#endif //PRESSION_HPP