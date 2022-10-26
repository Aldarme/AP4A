/**
 * @author Planchin Arnaud
 * @file Pression.cpp
 * @date 19/10/2022
 * @brief Définition des méthodes de la classe Pression
 */

#include "Pression.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Pression::aleaGenVal(int min, int max)
{
    bool signe;
    srand((int)time(0));
    if (data <= min){
        data = data + rand()%(2);           // Alea + lorsque la valeur est plus petite que le minimum
    } else if (data >= max){
        data = data - rand()%(2);           // Alea - lorsque la valeur est plus grande que le maximum
    } else {
        signe = (bool)(rand()%(2));         // Alea sur le signe pour une variation plus réaliste
        if(signe){
            data = data + rand()%(2);
        } else {
            data = data - rand()%(2);
        }
    }
    return data;
}

int Pression::GetData()
{
    return data;
}
