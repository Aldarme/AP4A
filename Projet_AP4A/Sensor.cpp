/**
 * @author choulot_hugo
 * @file Sensor.cpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

#include "Sensor.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

//constructeur par défaut
Sensor::Sensor(){
    m_valeur = aleaGenVal(ESensors::e_temperature);
}

//constructeur par valeur
Sensor::Sensor(const ESensors param_name){
    m_name = param_name;
    m_valeur = aleaGenVal(param_name);
}

//constructeur par recopie
Sensor::Sensor(const Sensor& s){
    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;
}

//destructeur
Sensor::~Sensor(){
    cout << "Destructeur appelle\n" << endl;
}

//operator
Sensor& Sensor::operator=(const Sensor& s){
    this->m_name = s.m_name;
    this->m_valeur = s.m_valeur;

    return *this;
}

/**
 * @brief permet de générer des valeurs aléatoires de int pour les différents capteurs
 * @return int
 * @param const ESensors name
 */
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

//constructeur par défaut
Temperature::Temperature(){
    m_name = ESensors::e_temperature;
    m_valeur = aleaGenVal(ESensors::e_temperature);
}

//constrcuteur par recopie
Temperature::Temperature(const Temperature& t){
    this->m_name = t.m_name;
    this->m_valeur = t.m_valeur;
}

//constructeur par défaut
Humidity::Humidity(){
    m_name = ESensors::e_humidity;
    m_valeur = aleaGenVal(ESensors::e_humidity);
}

//constructeur par recopie
Humidity::Humidity(const Humidity& h){
    this->m_name = h.m_name;
    this->m_valeur = h.m_valeur;
}

//constructeur par défaut
Light::Light(){
    m_name = ESensors::e_light;
    m_valeur = aleaGenVal(ESensors::e_light);
}

//constructeur par recopie
Light::Light(const Light& l){
    this->m_name = l.m_name;
    this->m_valeur = l.m_valeur;
}

//constructeur par défaut
Pression::Pression(){
    m_name = ESensors::e_pression;
    m_valeur = aleaGenVal(ESensors::e_pression);
}

//constructeur par recopie
Pression::Pression(const Pression& p){
    this->m_name = p.m_name;
    this->m_valeur = p.m_valeur;
}