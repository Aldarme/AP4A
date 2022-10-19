/**
 * @author Augustin Athané
 * @file Temperature.cpp
 * @date 08/10/2022
 * @brief Senor Temperature, classe fille de Sensor
*/
#include <iostream>
#include <cstdlib>
#include "Temperature.hpp"
#include "Sensor.hpp"
#include <chrono>
using namespace std::chrono;
#include <thread>
#include <ctime>
using namespace std;

//Constructeur par default
Temperature::Temperature(){
    type = e_temperature;
    simulation = false;
    MAX = 30;
    MIN = 15;
    value = floatRand(MIN, MAX);

}

//Constructeur par recopie
Temperature::Temperature(const Temperature &other){
    type = other.type;
    value = other.value;
    simulation = other.simulation;
    MAX = other.MAX;
    MIN = other.MIN;
}

//Destructeur
Temperature::~Temperature(){}

void Temperature::startSimulation(){
    simulation = true; // Comme la simulation est lançée, on modifie le booléen
    float temp;
    while(simulation){ // Boucle de simulation
        this_thread::sleep_for(chrono::milliseconds(500)); // Modification des valeur toutes les demis secondes
        temp = value + floatRand(-1, 1); //On ajoute à value la valeur aléatoire sortie par aleaGenVal()
        if(temp >= MIN && temp <= MAX){
            value = temp;
        }
    }
}
