#pragma once

//Je ne possede pas de serveur.cpp car lorsque j'essayais de l'utiliser j'avais l'erreur ("utilisation du type non defini 'serveur')
// J'ai donc tout mis au sein du serveur.hpp

#include <iostream>
#include <fstream>
#include <string>
#include "sensor.hpp"
#include "light.hpp"
#include "humidity.hpp"
#include "sound.hpp"
#include "temperature.hpp"
#include "scheduler.hpp"


using namespace std;

class serveur
{
private:


public:
	light l;
	sound s;
	humidity h;
	temperature t;
	scheduler sc;

	serveur() { //constructeur par défaut
		this->l.value = 0;
		this->l.name = 'l';
		this->s.value = 0;
		this->s.name = 's';
		this->h.value = 0;
		this->h.name = 'h';
		this->t.value = 0;
		this->t.name = 't';
	};


	serveur(temperature t, sound s, humidity h, light l) { //constructeur paramétré selon les capteurs
		this->t = t;
		this->h = h;
		this->l = l;
		this->s = s;
	};

	serveur(scheduler schedu) { //constructeur paramétré selon le scheduleur
		this->t = schedu.t;
		this->h = schedu.h;
		this->l = schedu.l;
		this->s = schedu.s;
	};

	serveur(const serveur& n) { //constructeur par recopie
		this->t = n.t;
		this->h = n.h;
		this->l = n.l;
		this->s = n.s;
	};
	serveur& operator=(const serveur&) {}; //operateur =
	~serveur() {}; //destructeur

	void consoleWrite() {  //ecrit toutes les valeurs des capteurs du serveur

		std::cout << "La valeur de la temperature est de " << this->t.value << endl;
		std::cout << "La valeur de l'humidité est de " << this->h.value << endl;
		std::cout << "La valeur de la lumiere est de " << this->l.value << endl;
		std::cout << "La valeur du son est de " << this->s.value << endl;
	};

	
	void fileWrite() { //ecrit la valeur de tous les capteurs dans des fichiers differents
		char reponse;

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur sound au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichiersound("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichiersound.csv");
			ofstream fluxsound(fichiersound.c_str(), ios::app);

			if (fluxsound)
			{
				fluxsound << "Temps;" << s.value <<endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier sound." << endl;
			}
		}

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur temperature au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;
		
		if (reponse == 'O') {
			string const fichiertemperature("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichiertemperature.csv");
			ofstream fluxtemperature(fichiertemperature.c_str(), ios::app);

			if (fluxtemperature)
			{
				fluxtemperature << "Temps;" << t.value << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier temperature." << endl;
			}
		}

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur light au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichierlight("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichierlight.csv");
			ofstream fluxlight(fichierlight.c_str(), ios::app);

			if (fluxlight)
			{
				fluxlight << "Temps;" << l.value <<endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier light." << endl;
			}
		}

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur humidity au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichierhumidity("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichierhumidity.csv");
			ofstream fluxhumidity(fichierhumidity.c_str(), ios::app);

			if (fluxhumidity)
			{
				fluxhumidity << "Temps;" << h.value <<endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier humidité." << endl;
			}
		}
	};

	friend class scheduler;


	//fonction utiliser pour le datarecovery 

	void consoleWritet(temperature ) { //écrit uniquement la valeur du capteur temperature

		std::cout << "Temperature:" << t.value << endl;
	};

	void consoleWriteh(humidity h) { //écrit uniquement la valeur du capteur humidité

		std::cout << "Humidité:" << h.value << endl;
	};
	void consoleWritel(light l) { //écrit uniquement la valeur du capteur light

		std::cout << "Lumiere:" << l.value << endl;
	};
	void consoleWrites(sound s) { //écrit uniquement la valeur du capteur sound

		std::cout << "Son:" << s.value << endl;

	};

	void fileWrites(sound s, int temps) { //ecrit la valeur du capteur son dans un fichier csv
		char reponse;

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur sound au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichiersound("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichiersound.csv");
			ofstream fluxsound(fichiersound.c_str(), ios::app);

			if (fluxsound)
			{
				fluxsound << temps << ";" << s.value << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier sound." << endl;
			}
		}
	};
	void fileWritet(temperature t, int temps) { //ecrit la valeur du capteur temperature dans un fichier csv
		char reponse;

		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur temperature au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichiertemperature("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichiertemperature.csv");
			ofstream fluxtemperature(fichiertemperature.c_str(), ios::app);

			if (fluxtemperature)
			{
				fluxtemperature << temps << ";" << t.value << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier temperature." << endl;
			}
		}
	};
	void fileWritel(light l, int temps) { //ecrit la valeur du capteur light dans un fichier csv
		char reponse;
		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur light au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichierlight("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichierlight.csv");
			ofstream fluxlight(fichierlight.c_str(), ios::app);

			if (fluxlight)
			{
				fluxlight << temps << ";" << l.value << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier light." << endl;
			}
		}
	};
	void fileWriteh(humidity h, int temps) { //ecrit la valeur du capteur humidité dans un fichier csv
		char reponse;
		cout << endl;
		cout << "Voulez vous enregistrer la valeur du capteur humidity au sein d'un fichier log? (O/N)" << endl;
		cin >> reponse;

		if (reponse == 'O') {
			string const fichierhumidity("C:/Users/OUBRAIM/AP4A/TPAP4A1/logs/fichierhumidity.csv");
			ofstream fluxhumidity(fichierhumidity.c_str(), ios::app);

			if (fluxhumidity)
			{
				fluxhumidity << temps << ";" << h.value << endl;
			}
			else
			{
				cout << "ERREUR: Impossible d'ouvrir le fichier humidité." << endl;
			}
		}
	};

	friend class scheduler;
};


