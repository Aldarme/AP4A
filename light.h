/*
∗ El Haddad Noor
∗ Light.h
∗ 18 / 10 / 2022
∗ Classe du capteur de Lumière
*/

#include <iostream>
#include <string>
#include <random>
#include "sensor.h"
#include <stdlib.h>


class Light : public Sensor
{
private:
	bool donnee;
public:
	void getData() {
		std::cout << donnee << std::endl;
	}
	void aleaGenVal() {
		int MIN = 1;
		int MAX = 2;
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<int> distr(MIN, MAX);
		int n = distr(eng);
		if (n == 1)
		{
			donnee = true;
		}
		else if (n == 2)
		{
			donnee = false;
		}
		
	}
	bool ReturnL()
	{
		aleaGenVal();
			
		return donnee;
	}
};
