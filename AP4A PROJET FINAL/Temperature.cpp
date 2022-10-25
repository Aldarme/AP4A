/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Temperature.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of temperature that is a child from sensor
 */

#include <time.h>
#include <random>
#include "Temperature.hpp"


//method that generates random values
float Temperature::aleaGenval()
{
    // initialize random seed: 
    srand (time(NULL));

    /* generate random number between 22 and 25: */
    float retval = (((float)rand())/RAND_MAX *25 + 22);
    return retval;
}

float Temperature::getData(){
	ret=aleaGenval();
	return ret;
}