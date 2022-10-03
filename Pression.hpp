/*
 @author Saad Sbat
 @file Pression.hpp
 @date 24/9/2022
 @C'est la classe du capteur Pression
 */
#ifndef PRESSION_HPP
#define PRESSION_HPP
#include "Sensor.hpp"


class Pression: public Sensor
{
	private:
		//char unite[50];
        char m_unite[100];
		friend class Server;
		friend class Scheduler;

	public:
		
        char m_type[12]="Pression";
		Pression();
		Pression(const char unite1[]);
		Pression(const Pression& autre);
		Pression& operator=(const Pression& autre);
		char* getUnite();
		void setUnite(const char unite2[]);


};
#endif