/**
* @author SZATKOWSKI Maxime
* @file Pressure.hpp
* @date 06/10/2022
* @brief  Fichier header contenant la d�finition des m�thodes de la classe Pressure
*/

// Define guards
#ifndef __Pressure_H__
#define __Pressure_H__

#include "Sensor.hpp"

/**
* @class Pressure
* @brief Permet de g�n�rer des objets capteurs de Pression
*/
class Pressure : public Sensor <float> {

public:

	//constructeur par d�faut des capteurs Pressure
	Pressure();

	//constructeur par recopie des capteurs Temperature
	Pressure(const Pressure& );

	//constructeur par recopie des capteurs Pressure
	~Pressure();

	//Op�rateur d'affectation
	Pressure& operator=(const Pressure& );


};

#endif  // Sensor_H
