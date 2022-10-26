/*
  Scheduler.cpp
 
   Created on: 2022/10/7
   Author: Z1ppo
 */
#include<iostream>
#include "unistd.h"
#include "Scheduler.h"
#include "Server.h"
#include "Temperature.h"
#include "Humidity.h"
#include "Pressure.h"
#include "Light.h"

using namespace std;

int getTime() {
return clock()/CLOCKS_PER_SEC;
}

Scheduler::Scheduler(){}
Scheduler::~Scheduler(){}

void Scheduler::Simulator(){
	Server server;
	Temperature t;
	Humidity h;
	Pressure p;
	Light l;

	int frequenceT=t.showFrequence();
	int frequenceH=h.showFrequence();
	int frequenceP=p.showFrequence();
	int frequenceL=l.showFrequence();
	char canLog;
	char canConsol;
	cout<<"Bienvenue dans le simulateur d'AVION！"<<endl;
	cout<<"Veuillez régler la fréquence de Temperature:"<<endl;
	cin>>frequenceT;
	cout<<"Veuillez régler la fréquence de Humidity:"<<endl;
	cin>>frequenceH;
	cout<<"Veuillez régler la fréquence de Pressure:"<<endl;
	cin>>frequenceP;
	cout<<"Veuillez régler la fréquence de Light:"<<endl;
	cin>>frequenceL;
	cout<<"Avez-vous besoin de Consol? Y/N"<<endl;
	cin>>canConsol;
	cout<<"Avez-vous besoin de Log? Y/N"<<endl;
	cin>>canLog;

	if(canConsol == 'Y' || canConsol == 'y'){
		server.setConsolActivation(true);
	}
	else if(canConsol == 'N'|| canConsol == 'n'){
		server.setConsolActivation(false);
	}

	if(canLog == 'Y' || canLog == 'y'){
		server.setLogActivation(true);
	}
	else if(canLog == 'N'|| canLog == 'n'){
		server.setLogActivation(false);
	}

	t.setFrequence(frequenceT-1);
	h.setFrequence(frequenceH-1);
	p.setFrequence(frequenceP-1);
	l.setFrequence(frequenceL-1);
	frequenceT=t.showFrequence();
	frequenceH=h.showFrequence();
	frequenceP=p.showFrequence();
	frequenceL=l.showFrequence();



	int lastTime = 0;

	bool exit=false;

	while(not exit){
		int now = getTime();
		if (now - lastTime > 0) {
			if(frequenceT!=0)
			{
				frequenceT-=1;
			}
			else
			{
				frequenceT=t.showFrequence();
				server.dataUpdate(temperature, t.getData());
				if(server.canConsol()){
					server.consolWrite(temperature);
				}
				if(server.canLog()){
					server.fileWrite(temperature);
				}
			}

			if(frequenceH!=0)
			{
				frequenceH-=1;
			}
			else
			{
				frequenceH=h.showFrequence();
				server.dataUpdate(humidity, h.getData());
				if(server.canConsol()){
					server.consolWrite(humidity);
				}
				if(server.canLog()){
					server.fileWrite(humidity);
				}
			}

			if(frequenceP!=0)
			{
				frequenceP-=1;
			}
			else
			{
				frequenceP=p.showFrequence();
				server.dataUpdate(pressure, p.getData());
				if(server.canConsol()){
					server.consolWrite(pressure);
				}
				if(server.canLog()){
					server.fileWrite(pressure);
				}
			}

			if(frequenceL!=0)
			{
				frequenceL-=1;
			}
			else
			{
				frequenceL=l.showFrequence();
				server.dataUpdate(light, l.getData());
				if(server.canConsol()){
					server.consolWrite(light);
				}
				if(server.canLog()){
					server.fileWrite(light);
				}
			}

		lastTime = now;
		}


	}
}





