/**
 * @author choulot_hugo
 * @file Sensor.cpp
 * @date 20/09/2022
 * @brief Classe mère des différents capteurs
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"

using namespace std;

//constructeur par défaut
Sensor::Sensor(){
    m_name = e_temperature;
    m_valeur = aleaGenVal();
}

//constructeur par valeur
Sensor::Sensor(const ESensors param_name){
    m_name = param_name;
    m_valeur = aleaGenVal();
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
int Sensor::aleaGenVal(){

    //srand (time(NULL));

    ESensors param_name = getName();
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

ESensors Sensor::getName(){
    return this->m_name;
}