#ifndef SENSOR_H
#define SENSOR_H
#pragma once
#include <string>
#include <iostream>

using namespace std;

template <class T> class  Sensor{
	protected:
		T value;
	private:
	public:
		string type;
		Sensor(){};
        T aleaGenVal();
		T getData();
        Sensor(const Sensor&); 
        Sensor &operator=(const Sensor&); 
        ~Sensor(){};
		

};

#endif