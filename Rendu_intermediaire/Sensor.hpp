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

/**
* @class Sensor
* @brief class m�re des diff�rents capteurs
*/
class Sensor
{

protected:

	int m_minValue;
	int m_maxValue;

public:

	// Definition de la forme canonique

	//Constructeur par d�faut
	Sensor();

	//Destructeur
	~Sensor();

	//Constructeur par recopie
	Sensor(const Sensor& valeur);

	//op�rateur d'affectation
	Sensor& operator=(const Sensor& s);

	/**
	* @brief fonction qui permet de g�n�rer les valeurs des capteurs
	* @return void
	* @param void
	*/
	int getData();

	/**
	* @brief permet de g�n�rere des valeurs al�atoires de type int
	* @return int
	* @param void
	*/
	int aleaGenVal();
};

#endif  // Sensor_H