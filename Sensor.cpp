#include "Sensor.hpp"
#include <cstdio>
#include <iostream>

using namespace std;

int Sensor::aleaGenVal()
{
    return (rand()%(max-min))+min;  //on a besoin d'une valeur aléatoire pour simuler un capteur
}

