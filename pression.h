/*
∗ El Haddad Noor
∗ Pression.h
∗ 18 / 10 / 2022
∗ Définition de la classe du capteur pression
*/
#include "sensor.h"
#include <stdlib.h>


class Pression : public Sensor
{
private:
	int donnee;
public:
	void getData() {
		std::cout << donnee << std::endl;
	}
	void aleaGenVal() {
		int MIN = 1;
		int MAX = 100;
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<int> distr(MIN, MAX);
		donnee = distr(eng);
	}
	int ReturnP()
	{
		aleaGenVal();
		return donnee;
	}
}; 
