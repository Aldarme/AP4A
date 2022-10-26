/**
 * @author Erhart Eliott
 * @file Light.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Light.hpp"

bool Light::aleaGenVal(bool min, bool max) 
	{
                srand((int)time(0));
                aleaVal = rand()%2;
                return aleaVal;
	}