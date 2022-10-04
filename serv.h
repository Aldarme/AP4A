#pragma once
#include <iostream>
#include <string>
using namespace std;

class serveur
{
private :
	float d_temp;
	float d_hum;
	float d_li;
	float d_press;
public:
	serveur();
	~serveur();
	void consolWrite();
	void fileWrite();
	void SetDonnees(float a,float b,float c,float d);


};