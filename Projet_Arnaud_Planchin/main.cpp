/**
 * @author Planchin Arnaud
 * @file Sensor.cpp
 * @date 03/10/2022
 * @brief Fonction main
 */

#include "Server.hpp"
#include "Sensor.hpp"
#include "Scheduler.hpp"
#include "Paquet.hpp"


int main(){

    Server s;
    Scheduler sched;                    // Initilisation des objets Server et Scheduler
    int temps=1;                        // Initialisation de la variable de temps pour se repérer dans le fichier à quel moment les données ont été récupérées

    s.fileRaZ();                        // Remise à zéro du fichier
    while (1)
    {
        sched.getAll();                 // Aqcuisition des données des Capteurs dans le Scheduler
        sched.serverSendData(s);        // Envoie des données au Server
        s.fileWrite(temps);             // Ecriture des données dans le fichier
        s.consolWrite(temps);           // Ecriture dans la console des données
        sched.wait();                   // Pause 
        temps++;                        // Incrémentation d'une seconde
    }

    return 0;
    
}