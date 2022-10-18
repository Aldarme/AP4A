/*
∗ El Haddad Noor
∗ serv.h
∗ 18 / 10 / 2022
∗ Définition de la Classe du serveur
*/
#pragma once
#include <iostream>
#include <string>


class Serveur
{
private :
	float d_temp;
	float d_hum;
	bool d_li;
	int d_press;
public:
	Serveur();
	~Serveur();
	void consolWrite();
	void fileWrite();
	void SetDonnees(float a,float b,bool c,int d);


};
