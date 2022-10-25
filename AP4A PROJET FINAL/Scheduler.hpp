/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Header file of scheduler which is responsible of receiving the data collected either to 
 * read or store it
 */
//#ifndef def_Scheduler
//#define def_Scheduler
//#include<iostream>
//#include<stdlib.h>
#include "Server.hpp"
#include "Light.hpp"
#include "Pressure.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
//#pragma once



class Scheduler
{
    private:
	Server sev;
	Temperature temp;
	Light lig;
	Pressure pres;
	Humidity hum;
    char myChar = ' ';

    public:
	    Scheduler(); 
        Scheduler (const Scheduler&){} 
        virtual ~Scheduler (){} 
        Scheduler &operator=(const Scheduler&){return *this;} 
        void getinfo();
};

//#endif




