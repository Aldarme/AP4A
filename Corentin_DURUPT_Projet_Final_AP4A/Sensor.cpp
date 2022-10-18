#include "Sensor.hpp"
#include <iostream>
#include <random>
using namespace std;

template <typename T>
Sensor<T>::Sensor(){}

template <typename T>
Sensor<T>::~Sensor(){}

template <typename T>
Sensor<T>::Sensor(string name){
    this->m_sensor_name = name;
    this->m_data = 0;
}

template <typename T>
T Sensor<T>::getData(){
    this->m_data = aleaGenVal();
    return this->m_data;
}
