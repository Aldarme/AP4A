#include "Scheduler.hpp"
#include <iostream>
#include <cstdlib>
#include <pthread.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

#define NUM_THREADS 4	//Définition du nombre de threads

int main() {

	Scheduler s;			//objet s de type Scheduler
	Server serv;

	int nb_iteration = 0;	//Temps de simulation

	//Saisie par l'utilisateur du temps de simulation et d'affichage des valeurs
	cout << "Veuillez saisir le temps de simulation" << endl;

	if (nb_iteration >= 0 && nb_iteration < 1000) {

		cin >> nb_iteration;
	}
	serv.setLogActivation();	//Demande à l'utilisateur s'il souhaite que les valeurs soient écrites dans le fichier log
	serv.setConsole();			//Demande à l'utilisateur s'il souhaite que les valeurs soient affichées dans la console

	//Affiche dans la console qu'une écriture à lieu dans le fichier log lorsque l'utilsateur ne veut pas afficher les valeurs dans la console
	if (serv.getConsoleActiv() == false && serv.getLogActiv())
	{
		cout << "writing on LogFile" << endl;
	}

	//Boucle de temps symbolisant la durée choisit par l'utilisateur
	for (int i = 0; i < nb_iteration; i++) {

		s.getData();								//récupèration les valeurs des capteurs grâce au scheduler

		if (serv.getConsoleActiv()) {				//Ecriture ou non dans la console selon la saisie de l'utilisateur

			serv.consoleWrite(s.sendData());		//écriture dans le fichier texte des valeurs des capteurs récupérées par le Scheduler
		}
		if (serv.getLogActiv()) {					//Ecriture ou non dans la console selon la saisie de l'utilisateur

			serv.fileWrite(s.sendData());	//écriture dans le fichier texte des valeurs des capteurs récupérées par le Scheduler

		}
		Sleep(1000);	//en millisecondes
	}
}
		//Sytème de multithreading non fonctionnel		

		/**
		pthread_t threads[NUM_THREADS];									//Création des threads
		int rc;
		int j;

		cout << endl;								

		for (j = 0; j < threads[j]; j++) {								//Choix du threads qui doit être appelé
			rc = pthread_create(&threads[i], NULL, PrintValue, (void*)i);

			if (rc) {
				cout << "Error:unable to create thread," << rc << endl;
				exit(-1);
			}
		}**
/**
* 
void* PrintValue(void* threadid) {
	
	s.getData();		//récupération des valeurs

	if (serv.getConsoleActiv()) {				

			serv.consoleWrite(s.sendData());		//appeler fonctions spécifiques à type de capteurs concerné
		}
		if (serv.getLogActiv()) {					

			serv.fileWrite(s.sendData());			//appeler fonctions spécifiques à type de capteurs concerné

		}
		Sleep(1000);		//choix de l'intervalle de temps //Temperature(1s), Humidity(2s), Pressure(4s), Light(10s)

	return NULL;
}
**/
