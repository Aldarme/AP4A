#include "Sensor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

Sensor::Sensor(){
    m_name = ESensors::e_temperature;
    m_valeur = aleaGenVal(ESensors::e_temperature);
}

Sensor::Sensor(const ESensors param_name){
    m_name = param_name;
    m_valeur = aleaGenVal(param_name);
}

Sensor::Sensor(const Sensor& s){
    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;
}

Sensor::~Sensor(){
    cout << "Destructeur appelle\n" << endl;
}

Sensor& Sensor::operator=(const Sensor& s){
    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;

    return *this;
}

int Sensor::aleaGenVal(const ESensors param_name){

    int m_valeur;

    switch (param_name){
        case e_temperature : m_valeur = rand() %50;
        break;
        case e_humidity : m_valeur = rand() %100;
        break;
        case e_light : m_valeur = rand() %12000;
        break;
        case e_pression : m_valeur = rand() %200;
        break;
    }

    return m_valeur;
}