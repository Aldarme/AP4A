/*
 @author Saad Sbat
 @file Humidity.hpp
 @date 24/9/2022
 @C'est la classe du capteur HUMIDITY
*/




#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP
#include <string>
#include "Sensor.hpp"
#include <iostream>

class Humidity: public Sensor
{
	private:
		char m_unite[100];
		char m_type[9]="Humidity";
		friend class Server;
		friend class Scheduler;
	//	char unite[50];
      
	public:
		
        
		Humidity();
		Humidity(const char unite1[]);
		char* getUnite();
		void setUnite(const char unite2[]);
		Humidity(const Humidity& autre);
		Humidity& operator=(const Humidity& autre);

};
#endif