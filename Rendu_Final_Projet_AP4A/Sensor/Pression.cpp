/**
 * @author Augustin Athané
 * @file Pression.cpp
 * @date 08/10/2022
 * @brief Senor Pression, classe fille de Sensor
*/
#include <iostream>
#include <cstdlib>
#include "Pression.hpp"
#include <chrono>
using namespace std::chrono;
#include "Sensor.hpp"
#include <thread>
#include <ctime>
using namespace std;


//Constructeur par default      
Pression :: Pression(){
    type = e_pression;
    simulation = false;
    MAX = 860;
    MIN = 400;
    value = intRand(MIN, MAX);
}

//Constructeur par recopie
Pression::Pression(const Pression &other){
    type = other.type;
    value = other.value;
    simulation = other.simulation;
    MAX = other.MAX;
    MIN = other.MIN;
}

//Destructeur
Pression::~Pression(){}


void Pression::startSimulation(){
    simulation = true; // Comme la simulation est lançée, on modifie le booléen 
    int temp;
    while(simulation){ // Boucle de simulation
        this_thread::sleep_for(chrono::milliseconds(500)); // Modification des valeur toutes les demis secondes
        temp = value + intRand(-2, 2); //On ajoute à value la valeur aléatoire sortie par aleaGenVal()
        if(temp >= MIN && temp <= MAX){
            value = temp;
        }
    }
}

//Retourne la valeur
int Pression::getData(){
    return value;
}
