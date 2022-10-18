/**
 * @author Tontsa apala frank
 * @file Humidity.cpp
 * @date 25/09/2022
 * @brief Humidity sensor
 */

#include<ctime>
#include<cstdlib>
#include "Humidity.hpp"

//Constructeur par defaut
Humidity::Humidity() {}

//Destructeur
Humidity::~Humidity() {}

//Constructeur par recopie
Humidity::Humidity(const Humidity &other) {}

//Operateur d'affectation
Humidity& Humidity::operator=(Humidity &&other) {
	return *this;
}

/*
 * Methode qui permet de generer une valeur d'humidite aleatoire
 */
float Humidity::aleaGenVal() {
	srand(time(0));// Fonction qui rend la valeur bien aleatoire
	float m_val = (((float)rand())/RAND_MAX * 50.0 - 20.0);//Valeur reel gener�es aleatoirement compris entre -20 et 30
	return m_val;
}

//Methode qui permet l'acces au valeur d'humidite en dehors de la classe
float Humidity::getData() {
	m_data=aleaGenVal();
	return m_data;
}
