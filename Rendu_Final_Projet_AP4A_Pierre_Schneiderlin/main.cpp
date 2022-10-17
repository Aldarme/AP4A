/**
 * @author Pierre Schneiderlin
 * @file main.cpp
 * @date 22/09/2022
 * @brief fichier source principal contenant l'implémentation des fonctions de "main.hpp" ainsi que la fontion "main()"
 * contenant le programme à exécuter
 */

#include "main.hpp"
#include "Scheduler.hpp"

using namespace std;

bool yesNoAnswerControl(char yes_p, char no_p)
{
    char answer;

    cin >> answer;                           // On attend la réponse de l'utilisateur, si celle-ci n'est pas conforme à l'une des deux attendues,
    while(answer!=yes_p&&answer!=no_p)                             // on lui demande de répondre à nouveau jusqu'à ce qu'il saisisse une réponse conforme
    {
        fflush(stdin);
        cout<<endl<<"Veuillez saisir Oui ("<<yes_p<<") ou Non ("<<no_p<<") > ";
        cin >> answer;
    }

    return (answer==yes_p);                      // On retourne ensuite true ou false en fonction de la réponse donnée par l'utilisateur

}

int intInputControl(int min_p, int max_p){

    int answer;
    cin>>answer;                            // On attend la réponse de l'utilisateur, si celle-ci n'est pas conforme à l'une des deux attendues,
    while((answer<min_p)||(answer>max_p))            // on lui demande de répondre à nouveau jusqu'à ce qu'il saisisse une réponse conforme
    {
        fflush(stdin);

        cout<<endl<<"Veuillez saisir un entier entre "<<min_p<<" et "<<max_p<<" ! > ";
        cin>>answer;
    }

    return answer;
}

int main()
{
    srand(time(nullptr));

    Scheduler scheduler;                    // Instanciation d'un objet de classe Scheduler

    scheduler.getServer().askValueAttribute();

    cout<<endl<<"Durant combien de periodes voulez-vous faire durer la simulation (en millier) ? > ";

    if(!scheduler.beginSimulation(intInputControl(0,60)))    // On lance la méthode de la classe serveur qui pilote tout le processus de
    {                                                                        //réception et d'envoi des données des capteurs au serveur
        cout<<endl<<"Vous avez bien quitte le programme !"<<endl;
    }
    return 0;
}

