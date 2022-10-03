/*
 @author Saad Sbat
 @file Light.hpp
 @date 24/9/2022
 @C'est la classe du capteur Light
*/


#ifndef LIGHT_HPP
#define LIGHT_HPP
#include "Sensor.hpp"


class Light: public Sensor
{
	private:
      	char m_unite[100];
        char m_type[12]="Light";
		friend class Server; 
		friend class Scheduler;
		


	public:
		//unite="dB";
		Light();
		Light(const char unite1[]);
		Light(const Light& autre);
		Light& operator=(const Light& autre);
		char* getUnite();
		void setUnite(const char unite2[]);


};
#endif