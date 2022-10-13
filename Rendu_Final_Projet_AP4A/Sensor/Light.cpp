/**
 * @author Augustin Athané
 * @file Light.cpp
 * @date 08/10/2022
 * @brief Senor Light, classe fille de Sensor
*/

#include <iostream>
#include <cstdlib>
#include "Light.hpp"
#include <chrono>
#include "Sensor.hpp"
using namespace std::chrono;
#include <thread>
#include <ctime>
using namespace std;


//Constructeur par default
Light :: Light(){
    type = e_light;
    simulation = false;
    MAX = 1;
    MIN = 0;
    value = intRand(MIN, MAX);
}

//Constructeur par recopie
Light::Light(const Light &other){
    type = other.type;
    value = other.value;
    simulation = other.simulation;
    MAX = other.MAX;
    MIN = other.MIN;
}

//Destructeur
Light::~Light(){}

void Light::startSimulation(){
    simulation = true; // Comme la simulation est lançée, on modifie le booléen 
    int aleaVal;
    while(simulation){ // Boucle de simulation
        this_thread::sleep_for(chrono::milliseconds(500)); // Modification des valeur toutes les demis secondes
        aleaVal = intRand(0, 10); // On génère un nombre entre 0 et 10
        // On décide qu'il y a 8 chances sur 10 pour que la valeur reste la même et donc 2 chances sur 10 pour que la valeur change
        //cout << aleaVal << endl;
        if(aleaVal >= 8){
            //cout << "light :" << value << endl;
            value = !value;
        }
    }
}

//Retourne la valeur
bool Light::getData(){
    return value;
}

