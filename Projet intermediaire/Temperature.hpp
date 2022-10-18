/**
 * @author Tontsa apala frank
 * @file Temperature.hpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */
#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "Sensor.hpp"

class Temperature : public Sensor<float> {
public:
	Temperature();
	virtual ~Temperature();
	Temperature(const Temperature &other);
	Temperature& operator=(Temperature &&other);

	//Redefinition de la premiere methode
	float getData();

protected:
	//Redefinition de la deuxieme methode
	float aleaGenVal();
};

#endif /* TEMPERATURE_H_ */
