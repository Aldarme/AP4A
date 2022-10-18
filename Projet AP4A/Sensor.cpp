/**
 * @author Tontsa apala frank
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief sensor
 */

#include <iostream>
#include "Sensor.hpp"

Sensor::Sensor(){
    val=0;
}

Sensor::Sensor(const Sensor& S)
{this->val = S.val;}

void Sensor::aleaGenVal(){
    val = (rand() %30);
}

Sensor& Sensor::operator=(const Sensor& S){
        this->val = S.val;
        return *this;
}

int Sensor::getData(){
    aleaGenVal();
    return val;
}

 Sensor::~Sensor(){}
