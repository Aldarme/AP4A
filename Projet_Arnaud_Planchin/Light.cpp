/**
 * @author Planchin Arnaud
 * @file Light.cpp
 * @date 19/10/2022
 * @brief Définition des méthodes de la classe Light
 */

#include "Light.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool Light::aleaGenVal(bool min,bool max)
{
    srand((int)time(0));
    data = (bool)(rand()%(2));
    return data;
}

bool Light::GetData()
{
    return data;
}