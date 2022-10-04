#include <iostream>
#include <string>
#include <fstream>
#include "serv.h"

using namespace std;

serveur::serveur()
{
	d_temp = 0;
	d_hum = 0;
	d_li = 0;
	d_press = 0;

}

serveur::~serveur()
{
	cout << "Le serveur est détruit" << endl;
}

void serveur::consolWrite()
{
	cout << "La temperature est :" << d_temp << endl;
	cout << "L'humidite est :" << d_hum << endl;
	cout << "La lumiere est de :" << d_li << endl;
	cout << "La pression est de :" << d_press << endl;
}

void serveur::SetDonnees(float a,float b,float c,float d)
{
	d_temp = a;
	d_hum = b;
	d_li = c;
	d_press = d;
}

void serveur::fileWrite()
{	
	float donnees[4];
	string const Logs("C:/Users/SANA/Desktop/Projet C++/Logs.txt");
	ofstream Flux(Logs.c_str());
	if (Flux)
	{
		Flux << "La temperature est :" << d_temp << endl;
		Flux << "L'humidite est :" << d_hum << endl;
		Flux << "La lumiere est de :" << d_li << endl;
		Flux << "La pression est de :" << d_press << endl;
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
}