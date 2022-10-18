/**
* @author MOhana wael
* @file : Temperature.cpp
* @date 27/09/2020
* @Description Declaration classe Temperature
*/

#include <iostream>
#include "./Temperature.hpp"


/***************CONSTRUCTORS***************/
//°C
//Default constructor
Temperature::Temperature():Sensor(0,'T',"°C"){};
//Constructor parametre
Temperature::Temperature(float a):Sensor(a,'T',"°C"){};
//Constructor par recopie
Temperature::Temperature(const Temperature& autre){ this->val = autre.val;}

/***************METHODS***************/
//gen random val
void Temperature::aleaGenVal(){
       srand(time(0));
    val  = (rand() %101) + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

/***************DESTRUCTOR***************/
Temperature::~Temperature(){}