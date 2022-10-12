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

class Light : protected Sensor
{
	private : 
		float m_lux;
	public : 
		Light(): m_lux(0.0f){};                 //Constructeur par défaut
		Light(const float& l):m_lux(l){};       //Constructeur par défaut
		virtual ~Light(){};                     //Destructeur
		Light &operator=(const Light& param_l)  //Opérateur d'affectation
		{
			this->m_lux = param_l.m_lux;
			return *this;
		};
		//function that collect lux from Light
		Light getData()
		{
			float _temp = Sensor::aleaGenVal();
			this->m_lux = _temp;
			return Light(_temp);
		};

		float getValue()
		{
			return this->m_lux;
		};

		std::string getType()
		{
			return "Light";
		};
};