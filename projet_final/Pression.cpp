/**
 * @author lois ROGER@
 * @file Pression.cpp
 * @date 05/09/2022
 * @brief capteur de pression
*/

#include "Pression.hpp"
#include <cstdlib>
#include <random>
#include <ctime>

int Pression::getVal() // fonction qui récupère une donnée aléatoire
{
    int maxi = 1000;
    int mini = 100;
    return aleaGenVal(mini, maxi);
}

int Pression::aleaGenVal(int mini, int maxi) // fonction qui génère une valeur aléatoire entre 2 valeur
{
    srand((unsigned int)time (0));
    int valaleatoire;
    valaleatoire = rand()%maxi +mini;
    return valaleatoire;
}
