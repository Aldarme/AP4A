/**
 * @author Planchin Arnaud
 * @file Humidity.cpp
 * @date 19/10/2022
 * @brief Définition des méthodes de la classe Humidity
 */

#include "Humidity.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float Humidity::aleaGenVal(float min, float max)
{
    bool signe;
    srand((int)time(0));
    if (data <= min){
        data = data + (float)(rand()%100)/70;           // Alea + lorsque la valeur est plus petite que le minimum
    } else if (data >= max){
        data = data - (float)(rand()%100)/70;           // Alea - lorsque la valeur est plus grande que le maximum
    } else {
        signe = (bool)(rand()%(2));                     // Alea sur le signe pour une variation plus réaliste
        if(signe){
            data = data + (float)(rand()%100)/70;
        } else {
            data = data - (float)(rand()%100)/70;
        }
    }
    return data;
}


float Humidity::GetData()
{
    return data;
}