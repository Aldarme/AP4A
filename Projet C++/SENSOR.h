#ifndef SENSOR_H
#define SENSOR_H
#pragma once

#include <string>
#include <iostream>
#include <ctime>  

using namespace std;

template <class T> class  Sensor
{
	protected:
		T value;
	private:
	public:
		string type;
		Sensor()
		{

		}
		~Sensor()
		{

		}
		T aleaGenVal();
		T getData();

};

#endif