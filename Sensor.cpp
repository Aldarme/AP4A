#include <iostream>
#include <cstdio>
#include <Windows.h>
#include "Sensor.hpp"


using namespace std;

Sensor::Sensor()
{
    
}


int Sensor::aleaGenVal()
{
    return (rand()%(max-min+1))+min; //genere random int entre min et max
}

int Sensor::getData()
{
    (*this).value = aleaGenVal();
    return (*this).value;
}


