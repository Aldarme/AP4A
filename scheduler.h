/*
∗ El Haddad Noor
∗ scheduler.h
∗ 18 / 10 / 2022
∗ Définition de la classe Scheduler
*/

#include <iostream>
#include <string>
#include "sensor.h"
#include "serv.h"
#include "humidite.h"
#include"light.h"
#include"pression.h"
#include"temperature.h"



class Scheduler
{
private:
	Serveur serv;
	Temperature temp;
	Light li;
	Pression press;
	Humidite hum;
public:
	Scheduler();
	Scheduler(Serveur a, Temperature b,Light c,Pression d, Humidite hum);
	float recuptemp();
	bool recupli();
	int recuppress();
	float recuphum();
	void recup();
	void send();
	void timer (int x);

};
