/**
 * @author mayer_thibault
 * @file Pressure.cpp
 * @date 02/10/2022
 * @brief
 */

#include "Sensor.hpp"
#include <cstdlib>
#include <iostream>

class Pressure : protected Sensor
{
	private : 
		float m_press;
	public : 
		Pressure():m_press(0.0f){};                        //Constructeur par défaut
		Pressure(const float& s):m_press(s){};             //Constructeur par recopie
		virtual ~Pressure(){};                             //Destructeur

		Pressure &operator=(const Pressure& param_s)                //Opérateur d'affectation 
		{
			this->m_press = param_s.m_press;
			return *this;
		};
		//function that collect press from Pressure
		Pressure getData()
		{
			float _temp = Sensor::aleaGenVal();
			this->m_press = _temp;
			return Pressure(_temp);
		};

		float getValue()
		{
			return this->m_press;
		};

		std::string getType()
		{
			return "Pressure";
		};
};