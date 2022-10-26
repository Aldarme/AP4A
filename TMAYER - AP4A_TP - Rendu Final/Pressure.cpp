/**
 * @author mayer_thibault
 * @file Pressure.cpp
 * @date 02/10/2022
 * @brief
 */

#include "Sensor.hpp"
#include <cstdlib>
#include <iostream>
#include "Pressure.hpp"

//Constructeur par défaut
Pressure::Pressure(): Sensor(){};                       

//Constructeur par recopie
Pressure::Pressure(const Pressure& s):Sensor(){};             

//Constructeur par paramètre
Pressure::Pressure(time_t period_p): Sensor(period_p){};      

//Opérateur d'affectation
Pressure& Pressure::operator=(const Pressure& param_s)                
{
	Sensor::operator=(param_s);
	return *this;
};

//function that collect press from Pressure
Data<int> Pressure::getData()
{
	int temp = (rand() % 100);
	Data<int> newData(temp, getType());
	this->updateLastTime();
	return newData;
};

std::string Pressure::getType()
{
	return "Pressure";
};