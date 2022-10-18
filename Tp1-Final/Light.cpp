/**
* @author MOhana wael
* @file : Light.cpp
* @date 27/09/2022
* @Description Definition classe Light
*/

#include <iostream>
#include "./Light.hpp"

/***************CONSTRUCTORS***************/

//Default constructor
Light::Light():Sensor(0,'L',"boolean"){};
//Constructor parametre
Light::Light(bool a):Sensor(a,'L',"boolean"){};
//Constructor par recopie
Light::Light(const Light& autre){ this->val = autre.val;}

/***************METHODS***************/
//gen random val
void Light::aleaGenVal(){ 
    if(rand() % 2 ) this->val  = true; 
                        else this->val  = false;
}

/***************DESTRUCTOR***************/
Light::~Light(){}