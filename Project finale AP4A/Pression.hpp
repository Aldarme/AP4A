/**
 * @author Tontsa apala frank
 * @file pression.hpp
 * @date 25/09/2022
 * @brief pressure sensor
 */
#ifndef PRESSION_H_
#define PRESSION_H_
#include "Sensor.hpp"

class Pression : public Sensor<int> {
public:
	Pression();
	virtual ~Pression();
	Pression(const Pression &other);
	Pression& operator=(Pression &&other);

	//Redefinition de la premiere methode
	int getData();

protected:
	//Redefinition de la deuxieme methode
	int aleaGenVal();
};

#endif  //PRESSION_H
