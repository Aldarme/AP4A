/**
 * @author DURUPT Corentin
 * @file Light.cpp
 * @date 14/10/2022
 * @brief this is the implementation of the sensors' Light
*/

#include "Light.hpp"
#include "Sensor.hpp"
#include <iostream>
using namespace std;

Light::Light(){}

Light::~Light(){}

Light::Light(string name) : Sensor(name) {}

bool Light::aleaGenVal() {
    int data_min = 0;
    int data_max = 100;
    bool result;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(data_min, data_max);

    if(distr(eng) == 0){
        result = false;
    } else if(distr(eng) == 1){
        result = true;
    }

    return result;
}