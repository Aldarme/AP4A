
#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "../hpp/Sensor.hpp"
#endif

#include <string>
#include <cstdlib>
#include <ctime>

Sensor::Sensor(){
}

Sensor::~Sensor()
{
}



int Sensor::aleaGenVal(){ //Fonction de generation de nombre aléatoire entre 1 et 10
    int randomNumber = rand() % 10 + 1;
    return randomNumber;
}


int Sensor::getData(){ // Fonction permettant de récuperer la donnée à envoyer
    return data;
}
