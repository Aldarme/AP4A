/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Light.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of light that is the child of sensor
 */

#include <time.h>
#include <random>
#include "Light.hpp"
//using namespace std;

 //method that generates random values
 bool Light::aleaGenval()
 {
    // initialize random seed: 
    srand (time(NULL));


    //generate random number between 0 and 2: 
    bool retval = (((bool)rand())/RAND_MAX * 1);
    return retval;

}

bool Light::getData(){
	ret=aleaGenval();
	return ret;
}