/**
* @author MOhana wael
* @file : Sensor.cpp
* @date 27/09/2022
* @Description Definition classe Sensor
*/

#include <iostream>
#include "./Sensor.hpp"

Sensor::Sensor(){
    val=0;
}

Sensor::Sensor(const Sensor& autre){this->val = autre.val;}
void Sensor::aleaGenVal(){
    val = rand() %30;
}

Sensor& Sensor::operator=(const Sensor& autre){
        this->val = autre.val;
        return *this;
}

int Sensor::getData(){
    aleaGenVal();
    return val;
}

 Sensor::~Sensor(){}
