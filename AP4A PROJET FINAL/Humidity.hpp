/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of humidity that is a child of sensor
 */
//#ifndef def_Humidity
//#define def_Humidity
#include "Sensor.hpp"


 
class Humidity : public Sensor<float> 
{
private:
	float aleaGenval();
public:
	Humidity(){}
	virtual ~Humidity(){}
	Humidity(const Humidity &other);
	Humidity& operator=(Humidity &other);

	//Redefinition de la premiere methode
	float getData();


};

//#endif

