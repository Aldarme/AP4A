#include <iostream>
#include <string>
#include "serv.h"
#include "sensor.h"
#include "scheduler.h"

using namespace std;

int main()
{	
	
	serveur serv;
	temperature temp;
	humidite hum;
	light li;
	pression press;
	scheduler test(serv,temp,li,press,hum);
	test.send();
	
	
	
		
	
return 0;
}