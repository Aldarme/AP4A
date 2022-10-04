#include <iostream>
#include <string>
#include <random>
#include "sensor.h"

using namespace std;

sensor::sensor()
{
	donnees = 0;
}

sensor::~sensor()
{
	cout << "Le capteur est détruit" << endl;
}

float sensor::getData()
{
	donnees = aleaGenVal();
	return donnees;
}

float sensor::aleaGenVal()
{
	float MIN = 1;
	float MAX = 100;
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(MIN, MAX);
	donnees = distr(eng);
	return donnees;
}
void sensor::setdata()
{
	
}