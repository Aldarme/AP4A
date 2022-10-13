/**
 * @author Augustin Athané
 * @file Humidity.cpp
 * @date 08/10/2022
 * @brief Senor Humidity, classe fille de Sensor
*/
#include <iostream>
#include <cstdlib>
#include "Humidity.hpp"
#include <chrono>
#include "Sensor.hpp"
using namespace std::chrono;
#include <thread>
#include <ctime>
using namespace std;


//Constructeur par default
Humidity::Humidity(){
    type = e_humidity;
    simulation = false;
    MAX = 100;
    MIN = 0;
    value = floatRand(MIN, MAX);
}

//Constructeur par recopie
Humidity::Humidity(const Humidity &other){
    type = other.type;
    value = other.value;
    simulation = other.simulation;
    MAX = other.MAX;
    MIN = other.MIN;
}

//Destructeur
Humidity::~Humidity(){}

void Humidity::startSimulation(){
    simulation = true; // Comme la simulation est lançée, on modifie le booléen
    float temp;
    while(simulation){ // Boucle de simulation
        this_thread::sleep_for(chrono::milliseconds(500)); // Modification des valeur toutes les demis secondes
        temp = value + floatRand(-1, 1); //On ajoute à value la valeur aléatoire sortie par floatRand
        //On vérifie que la nouvelle valeur est possible (comprise entre MIN et MAX)
        if(temp >= MIN && temp <= MAX){
            value = temp;
        }
    }
}

//Retourne la valeur
float Humidity::getData(){
    return value;
}
