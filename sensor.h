/*
∗ El Haddad Noor
∗ sensor.h
∗ 18 / 10 / 2022
∗ Définition de la classe mère des capteurs, la classe Sensor
*/

#pragma once
#include <iostream>
#include <string>


class Sensor 
{
private:
	float donnees;
public:
	Sensor();
	~Sensor();
	virtual void getData();
	float ReturnF();
protected:
	virtual void aleaGenVal();

};
