/**
 * @author mayer_thibault
 * @file Temperature.cpp
 * @date 02/10/2022
 * @brief
 */

#include "Temperature.hpp"

Temperature::Temperature():Sensor(){};                      			//Constructeur par défaut

Temperature::Temperature(const Temperature& t_p): Sensor(t_p){};        //Constructeur par recopie

Temperature::Temperature(time_t period_p): Sensor(period_p){};         //Constructeur par paramètre
Temperature& Temperature::operator=(const Temperature& param_t)   		//Opérateur d'affectation
{
	Sensor::operator=(param_t);
	return *this;
};

//function that collect kelvin from Temperature
Data<float> Temperature::getData()
{
	float temp = (rand() % 100)*0.9f;
	Data<float> newData(temp, getType());
	this->updateLastTime();
	return newData;
};

std::string Temperature::getType()
{
	return "Temperature";
};