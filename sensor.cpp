/*
∗ El Haddad Noor
∗ sensor.cpp
∗ 18 / 10 / 2022
∗ Implémentation de la classe sensor
*/

#include <iostream>
#include <string>
#include <random>
#include "sensor.h"

using namespace std;

Sensor::Sensor()
{
	donnees = 0;
}

Sensor::~Sensor()
{
	cout << "Le capteur est détruit" << endl;
}

void Sensor::getData()
{
	cout << donnees << endl;
}

void Sensor::aleaGenVal()
{
	float MIN = 1;
	float MAX = 100;
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(MIN, MAX);
	donnees = distr(eng);
	
}
float Sensor::ReturnF()

{
	aleaGenVal();
	return donnees;
}
