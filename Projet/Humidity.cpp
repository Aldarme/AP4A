/**
 * @author Erhart Eliott
 * @file Humidity.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Humidity.hpp"

float Humidity::aleaGenVal(float min, float max) 
	{
		bool sign;

		srand((int)time(0));

		if(aleaVal <= min)
		{
			aleaVal = aleaVal + (float)(rand()%10)/5;        
		}
		else if(aleaVal >= max)
		{
			aleaVal = aleaVal - (float)(rand()%10)/5;          
		}
		else
		{
			sign = (bool)(rand()%(2));                     
			if(sign)
			{
				aleaVal = aleaVal + (float)(rand()%10)/5;
			}
			else
			{
				aleaVal = aleaVal - (float)(rand()%10)/5;
			}
		}

		return aleaVal;
	}