// AP4A_Intermediaire.cpp : 
/**
 * @author SCHERRER Guillaume
 * @file AP4PTest.cpp
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

// instancier et initialiser le Scheduler:
int CapturePeriod = 2; // une valeur des capteurs toutes les CapturePeriod secondes
Scheduler MasterSched(CapturePeriod);

int main()
{
    //initialize random seed: 
    srand((int)time(NULL));

    std::cout << "scanning sensors...!  \n\n";

    MasterSched.ProcessScheduler();  // processus de capture cyclique des capteurs

    std::cout << "\n" << "stopped scanning ...!\n";

    system("pause"); // pour garder la console ouverte en "debug"
    return 0;
}
