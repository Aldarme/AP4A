#include <iostream>
#include <string>
#include "sensor.h"
#include "serv.h"
#include "humidite.h"
#include"light.h"
#include"pression.h"
#include"temperature.h"

using namespace std;

class scheduler
{
private:
	serveur serv;
	temperature temp;
	light li;
	pression press;
	humidite hum;
public:
	scheduler();
	scheduler(serveur a, temperature b,light c,pression d, humidite hum);
	float recuptemp();
	float recupli();
	float recuppress();
	float recuphum();
	void recup();
	void send();
	void timer (int x);

};