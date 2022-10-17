
#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
#include "Sensor.hpp"



class Temperature: public Sensor
{
	private://amitié avec ces classe pour qu'ils puissenet acceder aux attributs privee
		
		char unite[100];
		
		char type[12]="Temperature";
		//friend class Server;
		//friend class Scheduler;

	public:
		
		//char type[12]="Temperature";
		Temperature();
		Temperature(const char unite1[]);
		Temperature(const Temperature& autre);
		Temperature& operator=(const Temperature& autre);
	//	float getData();
	//	float aleaGenVal();
		char* gettype();
		
		char* getUnite();
		void setUnite(const char unite2[]);
};
#endif