/**
 * @author YUHUIFEI
 * @file HUMIDITY.cpp
 * @date 29/09/2022
 * @brief :La classe HUMIDITY permettra de caract¨¦riser un capteur d'humidit¨¦.
 */
#ifndef HUMIDTY_CPP
#define HUMIDITY_CPP

#include <iostream>
#include<string>
#include "Humidity.h"


class Humidity : public Sensor<float>
{
private:
	const string name = "Humidity";//G¨¦n¨¦ration de diff¨¦rents types de donn¨¦es en nommant les capteurs
	float m_humidity;// Le capteur d'humidit¨¦ transmet une valeur de type float.

public:
	Humidity()
	{
		cout << this->name << ":";
		this->type = "humidity";
		this->m_value = Sensor<float>::aleaGenVal();//Obtention de donn¨¦es al¨¦atoires
	}
	~Humidity()
	{

	}
	//Surcharge des fonctions
	Humidity& operator=(const Humidity& param_h)
	{
		this->m_humidity = param_h.m_humidity;
		return *this;
	}
	void sense();
};
#endif