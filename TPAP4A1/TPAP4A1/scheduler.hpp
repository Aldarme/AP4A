#pragma once

//Je ne possede pas de scheduler.cpp car lorsque j'essayais de l'utiliser j'avais l'erreur ("utilisation du type non defini 'serveur')
// J'ai donc tout mis au sein du scheduler.hpp

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "sensor.hpp"
#include "light.hpp"
#include "humidity.hpp"
#include "sound.hpp"
#include "temperature.hpp"

#include "serveur.hpp"
#include <windows.h>



using namespace std;

class serveur;

class scheduler
{
private:

public:
	light l;
	sound s;
	humidity h;
	temperature t;

	scheduler() {
		this->l.value = 0;
		this->l.name = 'l';
		this->s.value = 0;
		this->s.name = 's';
		this->h.value = 0;
		this->h.name = 'h';
		this->t.value = 0;
		this->t.name = 't';
	}
;

		scheduler(light l, sound s, humidity h, temperature t){
		this->l.value = l.value;
		this->l.name = l.name;
		this->s.value = s.value;
		this->s.name = s.name;
		this->h.value = h.value;
		this->h.name = h.name;
		this->t.value = t.value;
		this->t.name = t.name;
	}
;

	scheduler(const scheduler& n) {
		this->l.value = n.l.value;
		this->l.name = n.l.name;
		this->s.value = n.s.value;
		this->s.name = n.s.name;
		this->h.value = n.h.value;
		this->h.name = n.h.name;
		this->t.value = n.t.value;
		this->t.name = n.t.name;

	}
;
	scheduler& operator=(const scheduler&) {};
	~scheduler() {};

	friend class sensor <class T>;

	void datarecove() { //recuperation des valeurs et ecriture dans la console
		int valeur;
		int nblum, nbhum, nbtemp, nbson;
		char encore = 'O';

		cout << "Pendant combien de temps (entrer en s) voulez vous afficher de nouvelles valeurs (entrer un chiffre)? " << endl;
		cin >> valeur;
		cout << endl;
		cout << "Lumiere update toutes les (entrer en s): " << endl;
		cin >> nblum;
		cout << endl;
		cout << "Temperature update toutes les (entrer en s): " << endl;
		cin >> nbtemp;
		cout << endl;
		cout << "Humiditee update toutes les (entrer en s): " << endl;
		cin >> nbhum;
		cout << endl;
		cout << "Son update toutes les (entrer en s): " << endl;
		cin >> nbson;
		cout << endl;


		for (int compteur = 0; compteur <= valeur; compteur++)
		{

			cout << compteur << "s:" << endl;
			cout << endl;
			if (compteur % nbtemp == 0) {
				this->t.value = t.aleaGenVal();
				cout << "Temperature: " << this->t.value << endl;

			}
			if (compteur % nbson == 0) {
				this->s.value = s.aleaGenVal();
				cout << "Son: " << this->s.value << endl;

			}
			if (compteur % nbhum == 0) {
				this->h.value = h.aleaGenVal();
				cout << "Humidite: " << this->h.value << endl;

			}
			if (compteur % nblum == 0) {
				this->l.value = l.aleaGenVal();
				cout << "Lumiere: " << this->l.value << endl;
			}
			cout << endl;
			cout << endl;

			Sleep(1000);


		}
	}

	//fonction de base mais qui me met une ereur que je n'arrive pas à résoudre (les sources d'erreurs sont en //):
	
	// L'erreur étant "Utilisation du type non défini 'serveur'"
	
	void datarecovery(//serveur &scr
									) { //recuperation des valeurs et ecriture grace au fileWrite et consoleWrite 
		int valeur;
		int nblum, nbhum, nbtemp, nbson;
		char encore = 'O';

		cout << "Pendant combien de temps (entrer en s) voulez vous afficher de nouvelles valeurs (entrer un chiffre)? " << endl;
		cin >> valeur;
		cout << endl;
		cout << "Lumiere update toutes les (entrer en s): " << endl;
		cin >> nblum;
		cout << endl;
		cout << "Temperature update toutes les (entrer en s): " << endl;
		cin >> nbtemp;
		cout << endl;
		cout << "Humiditee update toutes les (entrer n s): " << endl;
		cin >> nbhum;
		cout << endl;
		cout << "Son update toutes les (entrer en s): " << endl;
		cin >> nbson;
		cout << endl;

		for (int compteur = 0; compteur <= valeur; compteur++)
		{

			cout << compteur << "s:" << endl;
			cout << endl;
			if (compteur % nbtemp == 0) {
				this->t.value = t.aleaGenVal();
				//scr.consoleWritet(this->t);
				//scr.fileWritet(this->t,compteur);

			}
			if (compteur % nbson == 0) {
				this->s.value = s.aleaGenVal();
				//scr.consoleWrites(this->s);
				//scr.fileWrites(this->s,compteur);

			}
			if (compteur % nbhum == 0) {
				this->h.value = h.aleaGenVal();
				//scr.consoleWriteh(this->h);
				//scr.fileWriteh(this->h,compteur);

			}
			if (compteur % nblum == 0) {
				this->l.value = l.aleaGenVal();
				//scr.consoleWritel(this->l);
				//scr.fileWriteh(this->h,compteur);
			}

			cout << endl;
			cout << endl;

			Sleep(1000);


		}

	}


	friend class serveur;
};



#endif