/**
 * @author RENON Emilien
 * @file Sensor.hpp
 * @date 21/09/2022
 * @brief La classe Sensor permettra de créer les données des capteurs.
 */

#include "Sensor.hpp"
using namespace std;

Temperature::Temperature(){
    this->m_name="Temperature";
    this->m_sensor=e_temperature;
}
Humidity::Humidity(){
    this->m_name="Humidity";
    this->m_sensor=e_humidity;
}
Light::Light(){
    this->m_name="Light";
    this->m_sensor=e_light;
}
Pression::Pression(){
    this->m_name="Pression";
    this->m_sensor=e_pression;
}

void Sensor::aleaValue(){
    switch(this->m_sensor){
        case e_temperature : 
        {
            this->m_value = rand()% 30 + 10; 
        }
        break;
        case e_humidity : 
        {
            this->m_value = rand()%20 + 10;
        }
        break;
        case e_light : 
        {
            this->m_value = rand()%2;
        }
        break;
        case e_pression : 
        { 
            this->m_value = rand()%2;
        }
        break;
    }
}

int Sensor::getValue(){
    return this->m_value;
}

ostream &operator<<(ostream &param_os, const Sensor &param_sensor){
    param_os << param_sensor.m_name <<" : "<<param_sensor.m_value<<endl;
    return param_os;
}

ofstream &operator<<(ofstream &param_of, const Sensor &param_sensor){
    param_of << param_sensor.m_name <<";"<<param_sensor.m_value<<";";
    return param_of;
}