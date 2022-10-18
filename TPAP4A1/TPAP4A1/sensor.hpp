#pragma once

//Je ne possede pas de sensor.cpp car lorsque j'essayais de l'utiliser j'avais l'erreur ("utilisation du type non defini 'sensor')
// J'ai donc tout mis au sein du sensor.hpp

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <random>
#include <time.h>


#include <iomanip>

using std::cout;
using std::endl;
using std::setprecision;

constexpr int FLOAT_MIN = 0; //Minimum des valeurs aleatoires
constexpr int FLOAT_MAX = 10; //Maximum des valeurs aleatoires

using namespace std;

template <typename T> class sensor
{
private:

public:
	T value;
	char name;

	sensor() //constructeur par défaut 
	{
		this->value = 0;
		this->name = 'a';
	}
		;
	sensor(int nombre, char lettre) //constructeur paramétré utilisant le type du temperature et sa valeur
	{
		this->value = nombre;
		this->name = lettre;
	}
		;
	sensor(char lettre) //constructeur paramétré calculant une valeur aleatoire selon le type du capteur
	{
		//this->value = aleaGenVal();
		this->value = 0;
		this->name = lettre;
	}
		;
	sensor(const sensor &s) { //constructeur par recopie
		this->value = s.value;
		this->name = s.name;
	}
	;
	//sensor& operator=(sensor& sn) { //operateur =
		//sn.value = this->value;
		//sn.name = this->value;
	//};
	~sensor() {};
	
	template <typename T> T aleaGenVal(); //methode qui genere des chiffres alétoires selon le type
	

	
	friend class scheduler;
};
