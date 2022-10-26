/**
 * @author Erhart Eliott
 * @file Pressure.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Pressure.hpp"

int Pressure::aleaGenVal(int min, int max) 
	{
		srand((int)time(0));
        aleaVal = rand()%(max-min + 1) + min;
		
        return aleaVal;
	}