/**
 * @author Planchin Arnaud
 * @file Temperature.cpp
 * @date 19/10/2022
 * @brief Définition des méthodes de la classe Temperature
 */

#include "Temperature.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

float Temperature::aleaGenVal(float min, float max)
{
    bool signe;
    srand((int)time(0));
    if (data <= min){
        data = data + (float)(rand()%100)/100;          // Alea + lorsque la valeur est plus petite que le minimum
    } else if (data >= max){
        data = data - (float)(rand()%100)/100;          // Alea - lorsque la valeur est plus grande que le maximum
    } else {
        signe = (bool)(rand()%(2));                     // Alea sur le signe pour une variation plus réaliste
        if(signe){
            data = data + (float)(rand()%100)/100;
        } else {
            data = data - (float)(rand()%100)/100;
        }
    }
    return data;
}


float Temperature::GetData()
{
    return data;
}
