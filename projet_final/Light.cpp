/**
 * @author lois ROGER
 * @file Light.cpp
 * @date 05/09/2022
 * @brief capteur de lumière
*/

#include "Light.hpp"
#include <cstdlib>
#include <random>
#include <ctime>


bool Light::getVal() // fonction qui récupère une donnée aléatoire
{
    bool mini = 0;
    bool maxi = 1;
    return aleaGenVal(mini, maxi); // fonction qui génère une valeur aléatoire entre 2 valeur
}

bool Light::aleaGenVal(bool mini, bool maxi)
{
    
    srand(time(0));
    return (bool)(rand()%(2));
}
    