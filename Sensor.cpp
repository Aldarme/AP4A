/**
 * @author DURUPT Corentin
 * @file Sensor.cpp
 * @date 21/09/2022
 * @brief This is the implementation of the different methods of the class Sensor.
*/

#include "Sensor.hpp"
#include <random>
#include <cstring>
using namespace std;

const int DATA_MIN = 1; //the minimum that a data can take
const int DATA_MAX = 100; // the maximum that a data can take

Sensor::Sensor(){
}

Sensor::~Sensor(){
}

Sensor::Sensor(string name){
    this->m_sensor_name = name;
    this->m_data = 0;
}

Sensor Sensor::getData(){
    return *this;
}

Sensor Sensor::aleaGenVal(){
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> distr(DATA_MIN, DATA_MAX);
    this->m_data = distr(eng);
    return *(this);
} 

ostream& operator<<(ostream& os, const Sensor& sensor){
    os << "'";
    os << sensor.m_sensor_name;
    os << "'" << " ";
    os << sensor.m_data;

    return os;
}

//Default constructor of the Temperature's Sensor
Temperature::Temperature(){}
//Default constructor of the Humidity's Sensor
Humidity::Humidity(){}
//Default constructor of the Light's Sensor
Light::Light(){}
//Default constructor of the Pressure's Sensor
Pressure::Pressure(){}
