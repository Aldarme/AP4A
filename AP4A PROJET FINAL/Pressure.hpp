/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of humidity
 */
//#ifndef def_Pressure
//#define def_Pressure
#include "Sensor.hpp"


class Pressure : public Sensor<int>
{
protected:
    int aleaGenval();

public:
    Pressure(){}
	virtual ~Pressure(){}
	Pressure(const Pressure &other){}
	Pressure& operator=(Pressure &other){return *this;}
	int getData();
};
 

//#endif