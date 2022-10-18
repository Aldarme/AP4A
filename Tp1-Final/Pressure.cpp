/**
* @author MOhana wael
* @file : Pressure.cpp
* @date 27/09/2022
* @Description Definition classe Pressure
*/

#include <iostream>
#include "./Pressure.hpp"


/***************CONSTRUCTORS***************/

//Default constructor
Pressure::Pressure():Sensor(0,'P',"hPa"){};
//Constructor parametre
Pressure::Pressure(int a):Sensor(a,'P',"hPa"){};
//Constructor par recopie
Pressure::Pressure(const Pressure& autre){ this->val = autre.val;}

/***************METHODS***************/
//gen random val
void Pressure::aleaGenVal(){val = rand() % 650;}

/***************DESTRUCTOR***************/
Pressure::~Pressure(){}