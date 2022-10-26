/*
 * Server.cpp
 *
 *  Created on: 2022/10/10
 *      Author: Z1ppo LI
 */

#include <iostream>
#include <fstream>
#include "Server.h"

using namespace std;

Server::Server(){
	t=0;
	h=0;
	p=0;
	l=0;
	consolActivation=0;
	logActivation=0;
}

Server::~Server(){}

void Server::dataUpdate(enum sensorType sT, float data){
	if(sT==temperature){
		t=data;
	}
	else if(sT==humidity){
		h=data;
	}
}

void Server::dataUpdate(enum sensorType sT, int data){
	p=data;
}

void Server::dataUpdate(enum sensorType sT, bool data){
	l=data;
}

void Server::consolWrite(enum sensorType sT){
	time_t rawtime;
	struct tm *ptminfo;
	time(&rawtime);
	ptminfo = localtime(&rawtime);
	printf("%02d-%02d-%02d %02d:%02d:%02d\n",
			ptminfo->tm_year+1900,ptminfo->tm_mon+1,ptminfo->tm_mday,
			ptminfo->tm_hour,ptminfo->tm_min,ptminfo->tm_sec);
	if(sT==temperature){
		cout<<"Temperature: "<<t<<" °C"<<endl;
	}
	else if(sT==humidity){
		cout<<"Humidity: "<<h<<" %"<<endl;
	}
	else if(sT==pressure){
		cout<<"Pressure: "<<p<<" kPa"<<endl;
	}
	else if(sT==light){
		if(l){
			cout<<"Light is on."<<endl;
		}
		else
		{
			cout<<"Light is off."<<endl;
		}

	}
}

void Server::fileWrite(enum sensorType sT)
{
	time_t rawtime;
		struct tm *ptminfo;
		time(&rawtime);
		ptminfo = localtime(&rawtime);
	if(sT==temperature){
		string ft="Temperature.txt";
		ofstream Filet(ft,ios::app);
		Filet<<"\n"<<ptminfo->tm_year+1900<<"-"<<ptminfo->tm_mon+1<<"-"<<ptminfo->tm_mday<<" "<<ptminfo->tm_hour<<":"<<ptminfo->tm_min<<":"<<ptminfo->tm_sec;
		Filet<<"\nTemperature:"<<t<<" °C";
		Filet.close();
	}
	else if(sT==humidity){
		string fh="Humidity.txt";
		ofstream Fileh(fh,ios::app);
		Fileh<<"\n"<<ptminfo->tm_year+1900<<"-"<<ptminfo->tm_mon+1<<"-"<<ptminfo->tm_mday<<" "<<ptminfo->tm_hour<<":"<<ptminfo->tm_min<<":"<<ptminfo->tm_sec;

		Fileh<<"\nHumidity:"<<h<<" %";
		Fileh.close();
	}
	else if(sT==pressure){
		string fp="Pressure.txt";
		ofstream Filep(fp,ios::app);
		Filep<<"\n"<<ptminfo->tm_year+1900<<"-"<<ptminfo->tm_mon+1<<"-"<<ptminfo->tm_mday<<" "<<ptminfo->tm_hour<<":"<<ptminfo->tm_min<<":"<<ptminfo->tm_sec;

		Filep<<"\nPressure:"<<p<<" kPa";
		Filep.close();
	}
	else if(sT==light){
		string fl="Light.txt";
		ofstream Filel(fl,ios::app);
		Filel<<"\n"<<ptminfo->tm_year+1900<<"-"<<ptminfo->tm_mon+1<<"-"<<ptminfo->tm_mday<<" "<<ptminfo->tm_hour<<":"<<ptminfo->tm_min<<":"<<ptminfo->tm_sec;

		if(l)
		{
			Filel<<"\nLight is on.";
		}
		else
		{
			Filel<<"\nLight is off.";
		}
		Filel.close();
	}
}

void Server::setConsolActivation(bool act){
	this->consolActivation=act;
}

void Server::setLogActivation(bool act){
	this->logActivation=act;
}

bool Server::canConsol(){
	return this->consolActivation;
}

bool Server::canLog(){
	return this->logActivation;
}
