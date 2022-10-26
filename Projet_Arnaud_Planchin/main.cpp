/**
 * @author Planchin Arnaud
 * @file main.cpp
 * @date 03/10/2022
 * @brief Fonction main
 */

//#include "Scheduler.hpp"

// Veuillez décommenter les include ci-dessous si vous avez des "undefined reference to" lors du build et commenter la ligne " #include "Scheduler.hpp" "

#include "Scheduler.cpp"
#include "Server.cpp"
#include "Paquet.cpp"
#include "Temperature.cpp"
#include "Pression.cpp"
#include "Light.cpp"
#include "Humidity.cpp"

int main(){

    Server s;
    Scheduler sched;                    // Initilisation des objets Server et Scheduler
    int pause_secondes = 1;             // Nombre de secondes de la pause
    int temps=0;                        // Initialisation de la variable de temps pour se repérer dans le fichier à quel moment les données ont été récupérées

    s.choix_Log();                      // Demande d'ecriture et/ou de d'affichage des Logs
    s.fileRaZ();                        // Remise à zéro du fichier
    while (1)
    {
        sched.getAll();                 // Aqcuisition des données des Capteurs dans le Scheduler
        sched.serverSendData(s,temps);  // Envoie les données au Server
        s.fileWrite(temps);             // Ecriture des données dans le fichier
        s.consolWrite(temps);           // Ecriture dans la console des données
        sched.wait(pause_secondes);     // Pause 
        temps+=pause_secondes;          // Incrémentation de temps de pause_seconde
    }

    return 0;
}
