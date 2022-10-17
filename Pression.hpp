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
        char unite[100];


	public:
		
        char type[12]="Pression";
		Pression();
		Pression(const char unite1[]);
		Pression(const Pression& autre);
		Pression& operator=(const Pression& autre);
		char* getUnite();
		void setUnite(const char unite2[]);
	//	float getData();
	//	float aleaGenVal();
		char* gettype();
		

};
#endif