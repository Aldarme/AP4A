/**
 * @author DURUPT Corentin
 * @file Pressure.cpp
 * @date 14/10/2022
 * @brief this is the implementation of the sensors' Pressure
*/

#include "Pressure.hpp"
#include "Sensor.hpp"
#include <iostream>
using namespace std;

Pressure::Pressure(){}

Pressure::~Pressure(){}

Pressure::Pressure(string name) : Sensor(name) {}

int Pressure::aleaGenVal(){
    int data_min = 0;
    int data_max = 100;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(data_min, data_max);

    return distr(eng);
}