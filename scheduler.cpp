#include <iostream>
#include <string>
#include <fstream>
#include "scheduler.h"

using namespace std;

scheduler::scheduler()
{
	
}
scheduler::scheduler(serveur a, temperature b, light c, pression d, humidite e)
{
	serv = a;
	temp = b;
	li = c;
	press = d;
	hum = e;
}

float scheduler::recuptemp()
{
	float a;
	a = temp.getData();
	return a;
}
float scheduler::recupli()
{
	float a;
	a = li.getData();
	return a;
}
float scheduler::recuphum()
{
	float a;
	a = hum.getData();
	return a;
}
float scheduler::recuppress()
{
	float a;
	a = press.getData();
	return a;
}

void scheduler::send()
{
	string b;
	serv.SetDonnees(recuptemp(),recuphum(),recupli(),recuppress());
	cout << "Voulez vous afficher les valeurs ou les stocker ? (réponses possibles : afficher ou stocker) " << endl;
	cin >> b;
	if ( b == "afficher")
	{
		serv.consolWrite();
	}
	else if (b == "stocker")
	{
		serv.fileWrite();
	}
	else
	{
		cout << "Réponse non supportée" << endl;
	}



}void scheduler::timer (int x)
{
	while (x != 0)
	{
		x = x - 1;
	}
	if (x = 0)
	{
		send();
	}
}