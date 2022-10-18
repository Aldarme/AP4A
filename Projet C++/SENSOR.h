/**
 * @author YUHUIFEI
 * @file SENSOR.h
 * @date 15/10/2022
 * @brief La classe Sensor permettra de cr¨¦er les donn¨¦es des capteurs.
 */
#ifndef SENSOR_H
#define SENSOR_H
#pragma once

#include <string>
#include <iostream>
#include <ctime>  

using namespace std;

//Utilisation des ¨¦num¨¦rations pour rendre les donn¨¦es plus concises
enum MySensor
{
	e_temperature,
	e_humidity,
	e_light,
	e_pression
}; 

template <class T> 
class  Sensor
{
	protected:
		T m_value;
		string m_name;
		MySensor m_sensor;
	private:
	public:
		string type;
		Sensor()
		{

		}
		Sensor(const Sensor& param_sensor);
		~Sensor()
		{

		}
		T aleaGenVal();
		T getData();
		template <class V>
		friend ostream& operator<<(std::ostream& param_os, const Sensor<V>& param_sensor);

		template <class V>
		friend ofstream& operator<<(std::ofstream& param_of, const Sensor<V>& param_sensor);
};

#endif//SENSOR.H