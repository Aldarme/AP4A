/**
 * @author Tontsa apala frank
 * @file Light.cpp
 * @date 25/09/2022
 * @brief Light sensor
 */

#include<ctime>
#include<cstdlib>
#include "Light.hpp"

//Constructeur par defaut
Light::Light() {}

//Destructeur
Light::~Light() {}

//Constructeur par recopie
Light::Light(const Light &other) {}

//Operateur d'affectation
Light& Light::operator=(Light &&other) {
	return *this;
}

//Methode qui permet de generer une valeur de lumiere aleatoire
bool Light::aleaGenVal() {
	srand(time(0)); //fonction qui rend la valeur bien aleatoire
	bool m_val = (((bool)rand())/RAND_MAX * 1);//Valeur gener�e compris entre 0 et 1 qui
	//est ensuite converti en booleen en utilisant du simple cast
	return m_val;
}

//Methode qui permet l'acces au valeur de lumiere en dehors de la classe
bool Light::getData() {
	m_data=aleaGenVal();
	return m_data;
}

