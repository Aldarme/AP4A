/**
 * @author Tontsa apala frank
 * @file pression.cpp
 * @date 25/09/2022
 * @brief pressure sensor
 */
#include<ctime>
#include<cstdlib>
#include "Pression.hpp"

//Constructeur par defaut
Pression::Pression() {}

//Destructeur
Pression::~Pression() {}

//Constructeur par recopie
Pression::Pression(const Pression &other) {}

//Operateur d'affectation
Pression& Pression::operator=(Pression &&other) {
	return *this;
}

//Methode qui permet de generer une valeur de pression aleatoire
int Pression::aleaGenVal() {
	srand(time(0)); // fonction qui rend la valeur generée aleatoire
	int m_val = (((int)rand())/RAND_MAX*50 - 10); //valeur gerenée compris entre -10 et 40
	return m_val;
}

//Methode qui permet l'acces au valeur de pression en dehors de la classe
int Pression::getData() {
	m_data=aleaGenVal();
	return m_data;
}
