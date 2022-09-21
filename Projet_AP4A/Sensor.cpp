#include "Sensor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

Sensor::Sensor(){

}

Sensor::Sensor(const int v){

}

Sensor::Sensor(const Sensor& s){

}

Sensor::~Sensor(){

}

Sensor& Sensor::operator=(const Sensor& s){

}

int Sensor::aleaGenVal(const ESensors param_name){

    int m_valeur;

    switch (param_name){
        case e_temperature : m_valeur = rand() %100;
        break;
        case e_humidity : ;
        break;
        case e_light : ;
        break;
        case e_pression : ;
        break;
    }

    return m_valeur;
}