/**
* @author SZATKOWSKI Maxime
* @file Humidity.hpp
* @date 06/10/2022
* @brief Fichier header contenant la d�finition des m�thodes de la classe Humidity
*/

// Define guards
#ifndef __Humidity_H__
#define __Humidity_H__

#include "Sensor.hpp"

class Humidity : public Sensor {

public:

	//constructeur par d�faut des capteurs Humidity
	Humidity();

	//constructeur par recopie des capteurs Temperature
	Humidity(const Humidity& h);

	//constructeur par recopie des capteurs Humidity
	~Humidity();

	//Op�rateur d'affectation
	Humidity& operator=(const Humidity& h);


};

#endif  // Sensor_H

