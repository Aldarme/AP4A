/**
 * @author Augustin Athané
 * @file Sensor.cpp
 * @date 24/09/2022
 * @brief Cette classe mère permet de créer les différents capteurs grâce à un lien d'héritage
 * Il vas falloir créer un thread, les valeurs seront modifiés toutes les secondes mais récupérer par le Scheduler à différentes periodes.
 * Pour plus de réalisme on pourra incrémenter par une valeur aléatoire (nég ou pos) plutôt que de créer une valeur aléatoire
 */

#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>
#include <thread>
#include "Sensor.hpp"
using namespace std;


//Constructeur par défault
Sensor::Sensor(){
    type = e_temperature;
    value = 0;
    simulation = false;
    MAX = 30;
    MIN = 16;
}

//Constructeur par recopie
Sensor::Sensor(const Sensor &other){
    type = other.type;
    value = other.value;
    simulation = other.simulation;
    MAX = other.MAX;
    MIN = other.MIN;
}

//Destructeur
Sensor::~Sensor(){}

//Méthodes
//Retourne la valeur
int Sensor::getData(){
    return value;
}

//Cette méthode génère aléatoirement la valeur du sensor
int Sensor::aleaGenVal(){
    int randMin;
    int randMax;

    //On calcul dabord l'équart entre le MIN et MAX ainsi que la moyenne
    int eqrt = MAX - MIN;
    int moy = MIN + eqrt/2;

    //On calcul ensuite sur quel portion se situe la valeur actuel ( premier tier superieur, deuxieme tière inferieur ...)
    if(value >= moy){ // Superieur à la moyenne
        if(value < moy + (1/3)*eqrt )
        { // Premier tier
            randMin-=0.10*eqrt;
            randMax+=0.08*eqrt;
        }else if (value < moy + (2/3)*eqrt) // deuxieme tier
        {
            randMin-=0.10*eqrt;
            randMax+=0.07*eqrt;         
        }else{ // troisieme tier
            randMin-=0.10*eqrt;
            randMax+=0.05*eqrt;
        }
        
    }else{ // Inferieur à la moyenne
        if(value > moy - (1/3)*eqrt ){ // Premier tier
            randMin=-0.08*eqrt;
            randMax=+0.10*eqrt;
        }else if (value > moy - (2/3)*eqrt) // deuxieme tier
        {
            randMin=-0.07*eqrt;
            randMax=+0.10*eqrt;            
        }else{ // troisieme tier
            randMin=-0.05*eqrt;
            randMax=+0.10*eqrt;
        }
        
    }

    int alea = intRand(randMin, randMax); //On retourne une valeur aléatoire entre randMin et randMax
    if(value + alea < MIN){alea = 0;}
    if(value + alea > MAX){alea = 0;}

    return alea;
}

void Sensor::startSimulation(){
    simulation = true; // Comme la simulation est lançée, on modifie le booléen 
    while(simulation){ // Boucle de simulation
        this_thread::sleep_for(chrono::milliseconds(500)); // Modification des valeur toutes les demis secondes
        value += aleaGenVal(); //On ajoute à value la valeur aléatoire sortie par aleaGenVal()
    }
}

// On créer notre propre fonction Rand pour que les valeurs aléatoires ne proviennent pas du thread_local, cette fonction est expliquée plus en détail dans le fichier readme 
// Pour le moment tous les sensor renvoient des int, mais il faudra changer cela pour le rendu final
int Sensor::intRand(const int & min, const int & max) {
    static std::mt19937 generator;
    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(generator);
}

void Sensor::endSimulation(){ // Fonction appelée pour arrêter la simulation
    simulation = false;
}


// Sous classes, constructeurs

//Constructeur par default
Temperature::Temperature(){
    type = e_temperature;
    simulation = false;
    MAX = 30;
    MIN = 16;
    value = intRand(MIN, MAX);

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

//Constructeur par default
Humidity::Humidity(){
    type = e_humidity;
    simulation = false;
    MAX = 100;
    MIN = 0;
    value = intRand(MIN, MAX);
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

int Light::aleaGenVal(){
    int alea = intRand(0, 10);
    if(alea <=8){ // 8 chances sur 10 que la valeur change
        if(value == 1){
            return -1;
        }else{
            return 1;
        }
    }

    return 0;
}

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
