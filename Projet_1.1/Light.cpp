/**
 * @author mayer_thibault
 * @file Light.cpp
 * @date 02/10/2022
 * @brief
 */

#include "Light.hpp"
#include "Sensor.hpp"
#include <cstdlib>
#include <iostream>

Light::Light(): m_lux(0.0f){}                 	//Constructeur par défaut

Light::Light(const float& l):m_lux(l){}      	//Constructeur par défaut

Light& Light::operator=(const Light& param_l)   //Opérateur d'affectation
{
	this->m_lux = param_l.m_lux;
	return *this;
}

//function that collect lux from Light
Light Light::getData()
{
	float _temp = Sensor::aleaGenVal();
	this->m_lux = _temp;
	return Light(_temp);
};

float Light::getValue()
{
	return this->m_lux;
};

std::string Light::getType()
{
	return "Light";
};