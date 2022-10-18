/*
∗ El Haddad Noor
∗ scheduler.cpp
∗ 18 / 10 / 2022
∗ Implémentation de la classe scheduler
*/

#include <iostream>
#include <string>
#include <fstream>
#include "scheduler.h"

using namespace std;

Scheduler::Scheduler()
{
	
}
Scheduler::Scheduler(Serveur a, Temperature b, Light c, Pression d, Humidite e)
{
	serv = a;
	temp = b;
	li = c;
	press = d;
	hum = e;
}

float Scheduler::recuptemp()
{
	float a = temp.ReturnF();
	return a;
}
bool Scheduler::recupli()
{
	
	bool a = li.ReturnL();
	return a;
}
float Scheduler::recuphum()
{
	float a = hum.ReturnF();
	return a;
}
int Scheduler::recuppress()
{
	int a = press.ReturnP();
	return a;
}

void Scheduler::send()
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



}void Scheduler::timer (int x)
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
