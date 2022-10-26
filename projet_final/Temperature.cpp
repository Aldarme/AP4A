/**
 * @author lois ROGER
 * @file Temperature.cpp
 * @date 05/09/2022
 * @brief capteur de température 
*/

#include "Temperature.hpp"
#include <cstdlib>
#include <random>
#include <ctime>




float Temperature::getVal() // fonction qui récupère une donnée aléatoire
{
    float maxi = 40.0;
    float mini = 15.0;
    return aleaGenVal(mini, maxi);
}

float Temperature::aleaGenVal(float mini, float maxi) // fonction qui génère une valeur aléatoire entre 2 valeur
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(mini, maxi);
    return dist(gen);
}

    
