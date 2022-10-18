/**
 * @author Tontsa apala frank
 * @file Humidity.hpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include "Sensor.hpp"

class Humidity : public Sensor<float> {
public:
	Humidity();
	virtual ~Humidity();
	Humidity(const Humidity &other);
	Humidity& operator=(Humidity &&other);

	//Redefinition de la premiere methode
	float getData();

protected:
	//Redefinition de la deuxieme methode
	float aleaGenVal();
};

#endif /* HUMIDITY_H_ */
