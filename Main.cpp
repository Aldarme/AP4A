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

		cin>>nb_iteration;
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

		cout << endl;								//Affiche la date et l'heure d'enregistrement des valeurs

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

/**

void* PrintHello(void* threadid) {
	long tid;
	tid = (long)threadid;
	cout << "Hello World! Thread ID, " << tid << endl;
	//pthread_exit(NULL);
	return NULL;
}

int main() {
	pthread_t threads[NUM_THREADS];
	int rc;
	int i;

	for (i = 0; i < NUM_THREADS; i++) {
		cout << "main() : creating thread, " << i << endl;
		rc = pthread_create(&threads[i], NULL, PrintHello, (void*)i);

		if (rc) {
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);
}**/
