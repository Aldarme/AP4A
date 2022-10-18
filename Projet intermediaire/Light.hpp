/**
 * @author Tontsa apala frank
 * @file Light.hpp
 * @date 25/09/2022
 * @brief Light sensor
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Sensor.hpp"

class Light : public Sensor<bool> {
public:
	Light();
	virtual ~Light();
	Light(const Light &other);
	Light& operator=(Light &&other);

	//Redefinition de la premiere methode
	bool getData();

protected:
	//Redefinition de la deuxieme methode
	bool aleaGenVal();
};

#endif /* LIGHT_H_ */
