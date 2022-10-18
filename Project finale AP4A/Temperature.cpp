/**
 * @author Tontsa apala frank
 * @file Temperature.cpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */

#include<ctime>
#include<cstdlib>
#include "Temperature.hpp"

//Constructeur par defaut
Temperature::Temperature() {}

//Destructeur
Temperature::~Temperature() {}

//Constructeur par recopie
Temperature::Temperature(const Temperature &other) {}

//Operateur d'affectation
Temperature& Temperature::operator=(Temperature &&other) {
	return *this;
}

//Methode qui permet de generer une valeur de temperature aleatoire
float Temperature::aleaGenVal() {
	srand(time(0)); //fonction qui rend la valeur à generer bien aleatoire
	return (((float)rand())/RAND_MAX * 80.0 - 45.0); // valeur generée compris entre -45 et 35
}

//Methode qui permet l'acces au valeur de temperature en dehors de la classe
float Temperature::getData() {
	m_data=aleaGenVal();
	return m_data;
}
