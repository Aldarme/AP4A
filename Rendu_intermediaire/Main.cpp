#include "Scheduler.hpp"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int main() {

	Scheduler s;
	Server serv;

	char f_path[513];		//path du fichier log
	int nb_iteration = 0;	//Temps de simulation

	//Saisie par l'utilisateur du chemin du fichier log
	cout << "veuillez saisir le chemin dans lequel vous souhaitez créer le fichier log" << endl;
	cin.getline(f_path, 512);

	//Saisie par l'utilisateur du temps de simulation et d'affichage des valeurs
	cout << "veuillez saisir le temps de simulation" << endl;

	if (nb_iteration >= 0 && nb_iteration < 1000) {

		cin>>nb_iteration;
	}
	serv.setLogActivation();	//Demande à l'utilisateur s'il souhaite que les valeurs soient écrites dans le fichier log
	serv.setConsole();			//Demande à l'utilisateur s'il souhaite que les valeurs soient affichées dans la console

	//Affiche dans la console qu'une écriture à lieu dans le fichier log lorsque l'utilsateur ne veut pas afficher les valeurs dans la console
	if (serv.getConsoleActiv() == false && serv.getLogActiv())
	{
		cout << "writing on : " << f_path << endl;
	}

	//Boucle de temps symbolisant la durée choisit par l'utilisateur
	for (int i = 0; i < nb_iteration; i++) {	

		cout << endl;								//Affiche la date et l'heure d'enregistrement des valeurs

		s.getData();								//récupèration les valeurs des capteurs grâce au scheduler

		if (serv.getConsoleActiv()) {				//Ecriture ou non dans la console selon la saisie de l'utilisateur

			serv.consoleWrite(s.sendData());		//écriture dans le fichier texte des valeurs des capteurs récupérées par le Scheduler
		}
		if (serv.getLogActiv()) {					//Ecriture ou non dans la console selon la saisie de l'utilisateur

			serv.fileWrite(f_path, s.sendData());	//écriture dans le fichier texte des valeurs des capteurs récupérées par le Scheduler

		}
		Sleep(1000);	//en millisecondes
	}
} 


