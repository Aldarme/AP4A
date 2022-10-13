/**
 * @author Augustin Athané
 * @file Sensor.cpp
 * @date 24/09/2022
 * @brief Cette classe mère permet de créer les différents capteurs grâce à un lien d'héritage
 **/

#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std::chrono;
#include <thread>
#include <ctime>
#include "Sensor.hpp"
using namespace std;


//Constructeur par défault
Sensor::Sensor(){
    type = e_temperature;
    simulation = false;
    MAX = 30;
    MIN = 16;
}

//Constructeur par recopie
Sensor::Sensor(const Sensor &other){
    type = other.type;
    simulation = other.simulation;
    MAX = other.MAX;
    MIN = other.MIN;
}

//Destructeur
Sensor::~Sensor(){}

//Méthodes
int Sensor::intRand(const int min, const int max) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);
    return distr(eng);
 }

float Sensor::floatRand(const float min, const float max) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<float> distr(min, max);
    return distr(eng);
 }

void Sensor::endSimulation(){ // Fonction appelée pour arrêter la simulation
    simulation = false;
}


