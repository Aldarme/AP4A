/**
* @author MOhana wael
* @file : Humidity.cpp
* @date 27/09/2022
* @Description Definition classe Humidity
*/

#include <iostream>
#include "./Humidity.hpp"

/***************CONSTRUCTORS***************/

//Default constructor
Humidity::Humidity():Sensor(0,'H',"%"){};
//Constructor parametre
Humidity::Humidity(float a):Sensor(a,'H',"%"){};
//Constructor par recopie
Humidity::Humidity(const Humidity& autre){ this->val = autre.val;}

/***************METHODS***************/
//gen random val
void Humidity::aleaGenVal(){ val = rand() % 101;};

/***************DESTRUCTOR***************/
Humidity::~Humidity(){};