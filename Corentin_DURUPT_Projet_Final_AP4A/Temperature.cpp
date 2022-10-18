/**
 * @author DURUPT Corentin
 * @file Temperature.cpp
 * @date 14/10/2022
 * @brief this is the implementation of the sensors' Temperature
*/

#include "Temperature.hpp"
#include "Sensor.hpp"
#include <iostream>
using namespace std;


Temperature::Temperature(){}

Temperature::~Temperature(){}

Temperature::Temperature(string name) : Sensor(name) {}

float Temperature::aleaGenVal() {
    float data_min = -15;
    float data_max = 50;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(data_min, data_max);

    return distr(eng);
}
