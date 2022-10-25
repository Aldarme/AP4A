/**
* @author SZATKOWSKI Maxime
* @file Sensor.hpp
* @date 15/09/2022
* @brief Fichier header contenant la définition des méthodes de la classe Sensor
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
* @brief class mère des différents capteurs
*/
template <class T>

class Sensor
{

protected:

	int m_minValue;
	int m_maxValue;

public:

	// Definition de la forme canonique

	//Constructeur par défaut
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

	//opérateur d'affectation
	Sensor& operator=(const Sensor& s)
	{
		this->m_maxValue = s.m_maxValue;
		this->m_minValue = s.m_minValue;

		return *this;
	}

	/**
	* @brief fonction qui permet de générer les valeurs des capteurs
	* @return int
	* @param void
	*/
	T getData()
	{
		return this->aleaGenVal();
	}
	//template <class T> getData();

	/**
	* @brief permet de générer des valeurs aléatoires de type int
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