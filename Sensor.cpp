/*author:TRABOULSI Rawan 
        *SENSOR
        *Créé le 27/09/2022*/

#include "Sensor.hpp"
using namespace std;
using std::cout;
#include <iostream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <string>


Sensor::Sensor():m_Smaxi(0),m_Smini(0),m_Svalue(15){

}

Sensor::Sensor(const Sensor & autre){
    m_Smaxi=autre.m_Smaxi;
    m_Smini=autre.m_Smini;
    m_Svalue=autre.m_Svalue;
}

Sensor & Sensor:: operator=(const Sensor & autre){
m_Smaxi=autre.m_Smaxi;
m_Smini=autre.m_Smaxi;
m_Svalue=autre.m_Svalue;
return *this;
}
Sensor::Sensor(int max_p, int min_p, int value_p):m_Smaxi(max_p),m_Smini(min_p),m_Svalue(value_p){
//constructeur par parametres
}

int Sensor::aleaGenVal(){

        srand((unsigned int)time(0));
		srand(time(0));
        m_Svalue=rand()%(m_Smaxi-m_Smini + 1) + m_Smini;
        /*int num = (rand() %
        (upper - lower + 1)) + lower;
        printf("%d ", num);*/
        return m_Svalue;
}

int Sensor :: getData(){
return aleaGenVal();
}

int Sensor:: getMaxi(){
return m_Smaxi;
} 

int Sensor:: getMini(){
return m_Smini;
} 

int Sensor:: getValue(){
return m_Svalue;
}

void Sensor :: setMax(int max_p){
	m_Smaxi=max_p;
}
void Sensor :: setMin(int min_p){
	m_Smini=min_p;
}
void Sensor :: setValue(int value_p){
	m_Svalue=value_p;
}
Sensor::~Sensor(){
    
}

