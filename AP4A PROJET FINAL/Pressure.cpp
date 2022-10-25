/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Pressure.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of pressure that is a child of sensor
 */

#include <time.h>
#include <random>
#include "Pressure.hpp"


//method that generates random values
int Pressure::aleaGenval()
{
  // initialize random seed: 
  srand (time(NULL));

  // generate random number between 10 and 13: 
  int retval = (((int)rand())/RAND_MAX * 13 + 10);
  return retval;
}

int Pressure::getData(){
	ret=aleaGenval();
	return ret;
}