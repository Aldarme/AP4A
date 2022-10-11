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
	cout << "veuillez saisir le chemin dans lequel vous souhaitez cr�er le fichier log" << endl;
	cin.getline(f_path, 512);

	//Saisie par l'utilisateur du temps de simulation et d'affichage des valeurs
	cout << "veuillez saisir le temps de simulation" << endl;

	if (nb_iteration >= 0 && nb_iteration < 1000) {

		cin >> nb_iteration;		//Saisie du temps de simulation par l'utilisateur
	}

	serv.setLogActivation();		//Demande � l'utilisateur s'il souhaite �crire dans le fichier log ou non
	serv.setConsole();				//Demande � l'utilisateur s'il souhaite �crire dans la console ou non

	//Affiche dans la console lorsqu'il y a ecriture dans le fichier log mais pas dans la console
	if (serv.getConsoleActiv() == false && serv.getLogActiv())
	{
		cout << "writing on : " << f_path << endl;
	}

	//Boucle de temps symbolisant la dur�e choisit par l'utilisateur
	for (int i = 0; i < nb_iteration; i++) {	

		cout << endl;								//Affiche la date et l'heure d'enregistrement des valeurs

		s.getData();								//r�cup�ration les valeurs des capteurs gr�ce au scheduler

		if (serv.getConsoleActiv()) {				//Ecriture ou non dans la console selon la saisie de l'utilisateur

			serv.consoleWrite(s.sendData());		//�criture dans le fichier texte des valeurs des capteurs r�cup�r�es par le Scheduler
		}
		if (serv.getLogActiv()) {					//Ecriture ou non dans la console selon la saisie de l'utilisateur

			serv.fileWrite(f_path, s.sendData());	//�criture dans le fichier texte des valeurs des capteurs r�cup�r�es par le Scheduler

		}
		Sleep(1000);	//en millisecondes
	}
} 


