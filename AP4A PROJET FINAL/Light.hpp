/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of humidity
 */
//#ifndef def_Light
//#define def_Light
#include "Sensor.hpp"

class Light : public Sensor<bool>
{
protected:
	//redefinition of the second function
	bool aleaGenval();
public:
	Light();
	virtual ~Light();
	Light(const Light &other);
	Light& operator=(Light &other);
	bool getData();
};
//#endif

