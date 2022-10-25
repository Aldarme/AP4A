/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of humidity that is the child of Sensor 
 */

#include <time.h>
#include <random>
#include "Humidity.hpp"


//method that generates random values
float Humidity::aleaGenval()
{
    // initialize random seed: 
    srand (time(NULL));
    
    // generate random number between 1 and 20:
    float retval = (((float)rand())/RAND_MAX *20 + 1);
    return retval;
}
float Humidity::getData() {
	ret=aleaGenval();
	return ret;
}