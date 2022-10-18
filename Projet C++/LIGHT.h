/**
 * @author YUHUIFEI
 * @file LIGHT.h
 * @date 29/09/2022
 * @brief :La classe LIGHT permettra de caract¨¦riser un capteur de luminance.
 */
#ifndef LIGHT_H
#define LIGHT_H
#include "SENSOR.h"
#pragma once

using namespace std;

class Light : public Sensor<bool>
{
private:
	const string name = "Light";//G¨¦n¨¦ration de diff¨¦rents types de donn¨¦es en nommant les capteurs
	bool m_light;//Le capteur de lumi¨¨re transmet une valeur de type bool¨¦en
public:
	Light()
	{
		cout << this->name << ":";
		this->type = "light";
		this->m_value = Sensor<bool>::aleaGenVal();
	}
	~Light()
	{

	}
	Light& operator=(const Light& param_l)
	{
		this->m_light = param_l.m_light;
		return *this;
	}
	void sense();
};
#endif//LIGHT.H