/**
 * @author mayer_thibault
 * @file Temperature.cpp
 * @date 02/10/2022
 * @brief
 */

#include <cstdlib>
#include <iostream>
#include "Sensor.hpp"

class Temperature : protected Sensor
{
  private:
	  float m_kelvin;
	public: 
		Temperature():m_kelvin(0.0f){};                           //Constructeur par défaut
		Temperature(const float& t):m_kelvin(t){};                //Constructeur par recopie
		virtual ~Temperature(){};                               //Destructeur
		Temperature &operator=(const Temperature& param_t)            //Opérateur d'affectation
		{
			this->m_kelvin = param_t.m_kelvin;
			return *this;
		};
		//function that collect kelvin from Temperature
		Temperature getData()
		{
			float _temp = Sensor::aleaGenVal();
			this->m_kelvin = _temp;
			return Temperature(_temp);
		};

		float getValue()
		{
			return this->m_kelvin;
		};

		std::string getType()
		{
			return "Temperature";
		};
};