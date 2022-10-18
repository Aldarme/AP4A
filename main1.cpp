#include <iostream>
#include <string>
#include "serv.h"
#include "sensor.h"
#include "scheduler.h"

using namespace std;

int main()
{	
	
	Serveur serv;
	Temperature temp;
	Humidite hum;
	Light li;
	Pression press;
	Scheduler test(serv,temp,li,press,hum);
	test.send();
	
	
	
		
	
return 0;
}
