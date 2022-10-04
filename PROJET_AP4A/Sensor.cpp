/**
 * @author RENON Emilien
 * @file Sensor.hpp
 * @date 21/09/2022
 * @brief La classe Sensor permettra de créer les données des capteurs.
 */

#include "Sensor.hpp"
using namespace std;

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
            this->m_value = rand()%100;
        }
        break;
        case e_pression : 
        { 
            this->m_value = rand()%20;
        }
        break;
    }
}

ostream &operator<<(ostream &param_os, const Sensor &param_sensor){
    param_os << param_sensor.m_name <<" : "<<param_sensor.m_value<<endl;
    return param_os;
}

ofstream &operator<<(ofstream &param_of, const Sensor &param_sensor){
    param_of << param_sensor.m_name <<";"<<param_sensor.m_value<<";";
    return param_of;
}