/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of humidity
 */
//#ifndef def_Temperature
//#define def_Temperature
//#include<iostream>
#include "Sensor.hpp"


class Temperature : public Sensor<float>
{
private:
    float aleaGenval();
public:
    
    Temperature(){}
    virtual~Temperature(){}
    Temperature(const Temperature &other){}
	Temperature& operator=(Temperature &other){return *this;}
    float getData();


};
 
//#endif

