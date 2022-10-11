/*!
 * @author  Cuenot Benoit  
 * @file    main.cpp
 * @date    10/10/2022  
 * @brief   Cette classe est le main où le programme s'exécute 
 */

#include <iostream>
#include "Sensor.cpp"
#include "Scheduler.cpp"
#include "Server.cpp"
#include "Temperature.cpp"
#include "Humidity.cpp"
#include "Pression.cpp"
#include "Light.cpp"

using namespace std;

int main(){

    Scheduler MyScheduler;

    MyScheduler.InformationsUtilisateur();

   while(1)
   {
            MyScheduler.Attendre(2000); /*!< Le choix de 2 secondes d'attentes est fixé*/
            MyScheduler.RecupData();
            MyScheduler.EnvoyerServer(true,true); /*!< Première argument : affichage console. Deuxième argument : Ecriture fichiers*/  
   }

   return 0;

}





