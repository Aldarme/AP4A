/**
 * @author Tontsa apala frank
 * @file pression.hpp
 * @date 25/09/2022
 * @brief pressure sensor
 */
#include <iostream>
#include "Sensor.hpp"
#ifndef PRESSION_H
#define PRESSION_H

class Pression : public Sensor{

public:
 	public : Pression():Sensor(){};

    public : Pression(const Pression& P);

~Pression();

};

#endif  //PRESSION_H
