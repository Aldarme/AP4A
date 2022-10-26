/**
 * @author A.BARTHELME
 * @file main.cpp
 * @date 26/10/2022
 * @brief Fichier permettant de lancer le scheduler
 * @version Finale 
*/

//executer le code via le main.exe ou via make puis ./main.exe


#include<iostream>
#include<string>
#include "Scheduler.hpp"
#include "Paquet.hpp"
#include "Serveur.hpp"
#include "AllSensor.hpp"
using namespace std;


int  main()
{
    Scheduler S1;
    S1.StartScheduler();
    return 1;
}
