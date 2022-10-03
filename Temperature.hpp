
#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
#include "Sensor.hpp"


class Temperature: public Sensor
{
	private://amitié avec ces classe pour qu'ils puissenet acceder aux attributs privee
		friend class Server;
		friend class Scheduler;
		char m_unite[100];
		
		char m_type[12]="Temperature";

	public:
		
		//char type[12]="Temperature";
		Temperature();
		Temperature(const char unite1[]);
		Temperature(const Temperature& autre);
		Temperature& operator=(const Temperature& autre);

		char* getUnite();
		void setUnite(const char unite2[]);
};
#endif