/**
 * @author A.BARTHELME
 * @file main.cpp
 * @date 12/10/2022
 * @brief Fichier permettant de lancere le scheduler
 * @version Intermediaire 
*/

/*SUITE A DES PROBLEMES DE COMPILATION j'ai du inclure les fichiers .cpp ici, ce qui n'est pas une bonne pratique,
mais je n'ai pas trouver d'autre solution.
L'erreur indiquait "undefined reference to" pour les fonctions de chaque fichier .cpp
*/


#include<iostream>
#include<string>
#include "Scheduler.hpp"
#include "Scheduler.cpp"
#include "Paquet.hpp"
#include "Paquet.cpp"
#include "Serveur.hpp"
#include "Serveur.cpp"
#include "AllSensor.hpp"
#include "Sensor.cpp"
#include "Temperature.cpp"
#include "Humidite.cpp"
#include "Pression.cpp"
#include "Luminosite.cpp"




using namespace std;



int  main()
{
    Scheduler S1;
    S1.StartScheduler();
    return 1;
}