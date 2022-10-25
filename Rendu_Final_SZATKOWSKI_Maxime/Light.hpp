/**
* @author SZATKOWSKI Maxime
* @file Light.hpp
* @date 06/10/2022
* @brief  Fichier header contenant la définition des méthodes de la classe Light
*/

// Define guards
#ifndef __Light_H__
#define __Light_H__

#include "Sensor.hpp"

class Light : public Sensor<bool> {

public:

	//constructeur par défaut des capteurs Light
	Light();

	//constructeur par recopie des capteurs Temperature
	Light(const Light& t);

	//constructeur par recopie des capteurs Light
	~Light();

	//Opérateur d'affectation
	Light& operator=(const Light& t);

};

#endif  // Sensor_H
