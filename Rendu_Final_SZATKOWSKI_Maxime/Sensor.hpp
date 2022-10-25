/**
* @author SZATKOWSKI Maxime
* @file Sensor.hpp
* @date 15/09/2022
* @brief Fichier header contenant la d�finition des m�thodes de la classe Sensor
*/

// Define guards
#ifndef __Sensor_H__
#define __Sensor_H__

#include "Packet.hpp"
#include <iostream>
#include <random>

using namespace std;

/**
* @class Sensor
* @brief class m�re des diff�rents capteurs
*/
template <class T>

class Sensor
{

protected:

	int m_minValue;
	int m_maxValue;

public:

	// Definition de la forme canonique

	//Constructeur par d�faut
	Sensor()
	{
		m_minValue = 0;
		m_maxValue = 0;
	}

	//Destructeur
	~Sensor(){}

	//Constructeur par recopie
	Sensor(const Sensor& s)
	{
		this->m_maxValue = s.m_maxValue;
		this->m_minValue = s.m_minValue;
	}

	//op�rateur d'affectation
	Sensor& operator=(const Sensor& s)
	{
		this->m_maxValue = s.m_maxValue;
		this->m_minValue = s.m_minValue;

		return *this;
	}

	/**
	* @brief fonction qui permet de g�n�rer les valeurs des capteurs
	* @return int
	* @param void
	*/
	T getData()
	{
		return this->aleaGenVal();
	}
	//template <class T> getData();

	/**
	* @brief permet de g�n�rer des valeurs al�atoires de type int
	* @return int
	* @param void
	*/
	T aleaGenVal()
	{
		int MIN = this->m_minValue;
		int MAX = this->m_maxValue;

		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<T> distr(MIN, MAX);
		T alea = distr(eng);

		return alea;
	}
};

#endif  // Sensor_H