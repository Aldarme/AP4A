/*!
 * @author  Cuenot Benoit  
 * @file    main.cpp
 * @date    25/10/2022  
 * @brief   Cette classe est le main où le programme s'exécute 
 */

#include <iostream>
#include "../include/Sensor.hpp"
#include "Scheduler.cpp"
#include "Server.cpp"

using namespace std;

int main(){

    Scheduler MyScheduler;  
    MyScheduler.ChoixUtilisateur(); /*!< L'utilisateur choisi l'affichage console et le log des données*/

   while(1)
   {
            MyScheduler.HorlogeInterne(); /*!< Horloge interne*/
            MyScheduler.RecupAndSendData(); /*!< Récupération des données et envoie au server*/
   }

   return 0;
}





