/**
 * @author DURUPT Corentin
 * @file Humidity.cpp
 * @date 14/10/2022
 * @brief this is the implementation of the sensors' Humidity
*/

#include "Humidity.hpp"
#include "Sensor.hpp"
#include <iostream>
using namespace std;

Humidity::Humidity(){}

Humidity::~Humidity(){}

Humidity::Humidity(string name) : Sensor(name) {}

float Humidity::aleaGenVal(){
    float data_min = 0;
    float data_max = 100;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(data_min, data_max);

    return distr(eng);
}