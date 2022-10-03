/**
 * @author Pierre Schneiderlin
 * @file main.cpp
 * @date 22/09/2022
 * @brief fichier source principal contenant l'implémentation des fonctions de "main.hpp" ainsi que la fontion "main()"
 * contenant le programme à exécuter
 */

#include "main.hpp"
#include "Server.hpp"
#include "Sensors.hpp"
#include "Scheduler.hpp"

using namespace std;

bool yesNoAnswerControl()
{
    char answer;

    cin >> answer;                           // On attend la réponse de l'utilisateur, si celle-ci n'est pas conforme à l'une des deux attendues,
    while(answer!='O'&&answer!='N')                             // on lui demande de répondre à nouveau jusqu'à ce qu'il saisisse une réponse conforme
    {
        cout<<endl<<"Veuillez saisir Oui (O) ou Non (N) >";
        cin >> answer;
    }

    if(answer=='O')                      // On retourne ensuite true ou false en fonction de la réponse donnée par l'utilisateur
    {
        return true;
    }
    return false;
}

int main()
{
    srand(time(nullptr));

    Scheduler scheduler;                    // Instanciation d'un objet de classe Scheduler

    cout<<endl<<"Souhaitez-vous ecrire les donnees dans la console ? (Oui (O) ou Non (N) >";  // Définitions des modalités d'écriture de l'objet de classe
    scheduler.getServer().setConsolActivation(yesNoAnswerControl());                          // Server, attribut de l'objet Scheduler

    cout<<endl<<"Souhaitez-vous ecrire les donnees dans les fichiers de log ? (Oui (O) ou Non (N) >";
    scheduler.getServer().setLogActivation(yesNoAnswerControl());


    scheduler.sendDataToServer(20);            /* On lance la méthode de la classe serveur qui pilote tout le processus de
                                                    réception et d'envoi des données des capteurs au serveur*/
    return 0;
}

