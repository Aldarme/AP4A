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
#include <ctime>
#include <iomanip>
#include <limits>

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
	~Sensor() {}

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

	/**
	* @brief permet de g�n�rer des valeurs al�atoires de type 
	* @return type T g�n�rique
	* @param void
	*/
	T aleaGenVal()
	{
		T MIN = this->m_minValue;
		T MAX = this->m_maxValue;

		srand((unsigned)time(0));

		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		T alea = generateRandomNumber(MIN, MAX);

		return alea;
	}


	T generateRandomNumber(T startRange, T endRange)
	{
		T randNum = startRange + (T)rand() / ((T)RAND_MAX / (T)(endRange - startRange));
		return(randNum);
	}
};
#endif  // Sensor_H