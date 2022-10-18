/**
 * @author YUHUIFEI
 * @file TEMPERARURE.h
 * @date 29/09/2022
 * @brief :La classe TEMPERATURE permettra de caract¨¦riser un capteur de temp¨¦rature.
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "SENSOR.h"
#pragma once

using namespace std;


class Temperature : public Sensor<int>
{
private:
	const string name = "Temperature";//G¨¦n¨¦ration de diff¨¦rents types de donn¨¦es en nommant les capteurs
	int m_temperature; //Le capteur de temperature transmet une valeur de type int
public:
	Temperature()
	{
		cout << this->name << ":";
		this->type = "temperature";
		this->m_value = Sensor<int>::aleaGenVal();
	}
	~Temperature()
	{

	}
	Temperature& operator=(const Temperature& param_t) 
	{
		this->m_temperature = param_t.m_temperature;
		return *this;
	};
	void sense();
};
#endif//TEMPERATURE.H

