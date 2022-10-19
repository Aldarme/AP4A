/**
 *@author Lola ROQUILLON 
 *@file main.cpp
 *@date 28/09/2022
 *@brief Classe principale qui créer le scheduler et qui lance le programme de base
 */

#include "Scheduler.hpp"
#include <iostream>

int main()
{ 
    Scheduler scheduler;        //créer un scheduler
    scheduler.ScheStart();      //appel de la fonction qui demare la simulation
    return 0;
}