/*
∗ El Haddad Noor
∗ serv.cpp
∗ 18 / 10 / 2022
∗ Implémentation de la classe serveur
*/

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "serv.h"

using namespace std;

Serveur::Serveur()
{
	d_temp = 0;
	d_hum = 0;
	d_li = 0;
	d_press = 0;

}

Serveur::~Serveur()
{
	cout << "Le serveur est détruit" << endl;
}

void Serveur::consolWrite()
{
	cout << "La temperature est :" << d_temp << "°C" << endl;
	Sleep(1000);
	cout << "L'humidite est :" << d_hum << "g/m³" << endl;
	Sleep(1500);
	if (d_li == true) {
		cout << "La lumiere est : True" << endl;
	}
	else if (d_li == false) {
		cout << "La lumiere est : False" << endl;
	}
	Sleep(2000);
	cout << "La pression est de :" << d_press << "hPa" << endl;
}

void Serveur::SetDonnees(float a,float b,bool c,int d)
{
	d_temp = a;
	d_hum = b;
	d_li = c;
	d_press = d;
}

void Serveur::fileWrite()
{	
	
	string const Logs("C:/Users/SANA/Desktop/Projet C++/Log_Temp.txt");
	ofstream Flux(Logs.c_str());
	if (Flux)
	{
		Flux << "La temperature est de :" << d_temp << "°C" << endl;
		
	}
	else
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
	string const Log("C:/Users/SANA/Desktop/Projet C++/Log_Hum.txt");
	ofstream Flu(Log.c_str());
	if (Flu)
	{
		Flu << "L'humidite est :" << d_hum << "g/m³" << endl;

	}
	else
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
	string const Lo("C:/Users/SANA/Desktop/Projet C++/Log_Li.txt");
	ofstream Fl(Lo.c_str());
	if (Fl)
	{
		if (d_li == true) {
			Fl << "La lumiere est : True" << endl;
		}
		else if (d_li == false) {
			Fl << "La lumiere est : False" << endl;
		}

	}
	else
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}
	string const L("C:/Users/SANA/Desktop/Projet C++/Log_Press.txt");
	ofstream F(L.c_str());
	if (F)
	{
		F << "La pression est de :" << d_press << "hPa" << endl;

	}
	else
	{
		cout << "Impossible d'ouvrir le fichier" << endl;
	}



		
	
	

	
}
