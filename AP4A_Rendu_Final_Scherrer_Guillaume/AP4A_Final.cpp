/**
 * @author SCHERRER Guillaume
 * @file AP4P_Intermediaire.cpp
 * @date 09/2022
 * @brief programme principal de gestion des capteurs
 *
*/

// génériques:
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

// classes:
#include "Scheduler.hpp"
#include "Server.hpp"
#include "AP4A_Final.hpp"


int main()
{
    //initialize random seed: 
    srand((int)time(NULL));
   
   // Accueil: 
    int PeriodesCapteurs[4];
    std::cout << "\n" << "_____Capture séquentielle de capteurs_____\n";
    std::cout << "\n" << "Veuillez entrer la période de capture pour chaque capteur (en secondes entières)\n";
    std::cout << "\n" << "Température: ";
    std::cin >> PeriodesCapteurs[T];
    std::cout << "\n" << "Humidité: ";
    std::cin >> PeriodesCapteurs[H];
    std::cout << "\n" << "Pression: ";
    std::cin >> PeriodesCapteurs[P];
    std::cout << "\n" << "Lumière: ";
    std::cin >> PeriodesCapteurs[L];
  
    
    // instancier et initialiser le Scheduler:
    float CapturePeriod = 1; // Timing de base 1Hz ( 1 seconde)
    Scheduler MasterSched(CapturePeriod, PeriodesCapteurs);
    
    MasterSched.ProcessScheduler();  // processus de capture cyclique des capteurs

    std::cout << "\n" << "Arrêt des mesures ...!\n";

    //system("pause"); // pour garder la console ouverte en "debug" --> utilisé dans Visual Studio normal
    return 0;
}
